#include <gtest/gtest.h>
#include "my_class.h"

TEST(MyClassTest, DoSomething) {
    MyClass myClass;
    EXPECT_EQ(myClass.doSomething(), 42);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
