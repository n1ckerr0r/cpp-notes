#include <gtest/gtest.h>
#include <sstream>
#include "main.h"

TEST(TestSuitName, TestName) {
    int a = 10;

    EXPECT_TRUE(func(a) == 2 * a);
    EXPECT_FALSE(func(a) != 2 * a);
    EXPECT_EQ(func(a), 2*a);
    EXPECT_THROW(func(std::numeric_limits<int>::max()/2 + 1), std::runtime_error);

    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    func1(a);
    std::cout.rdbuf(old_cout);

    EXPECT_EQ(buffer.str(), "result: 10");
}