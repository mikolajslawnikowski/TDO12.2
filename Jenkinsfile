pipeline {
    agent any
    
    environment {
        CC = 'g++'
        TEST_FRAMEWORK = 'gtest'
    }

    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/mikolajslawnikowski/TDO12.2.git'
            }
        }
        stage('Build') {
            steps {
                sh '''
                mkdir -p build
                cd build
                cmake ..
                make
                '''
            }
        }
        stage('Unit Test') {
            steps {
                sh '''
                cd build
                make test
                '''
            }
        }
        stage('Code Coverage') {
            steps {
                sh '''
                cd build
                gcovr -r .. --xml -o coverage.xml
                '''
            }
            post {
                always {
                    jacoco execPattern: 'build/*.exec'
                }
            }
        }
        stage('Static Analysis') {
            steps {
                sh '''
                cppcheck --enable=all --inconclusive --xml --xml-version=2 . 2> cppcheck.xml
                '''
            }
            post {
                always {
                    recordIssues tools: [cppCheck(pattern: 'cppcheck.xml')]
                }
            }
        }
        stage('SonarQube Analysis') {
            environment {
                scannerHome = tool 'SonarQube Scanner'
            }
            steps {
                withSonarQubeEnv('SonarQube') {
                    sh "${scannerHome}/bin/sonar-scanner"
                }
            }
        }
    }

    post {
        always {
            junit 'build/test-reports/*.xml'
        }
        success {
            echo 'Pipeline succeeded!'
        }
        failure {
            echo 'Pipeline failed!'
        }
    }
}
