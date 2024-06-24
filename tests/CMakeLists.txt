add_executable(runTests test_my_class.cpp)
target_link_libraries(runTests gtest gtest_main)
add_test(runTests runTests)
