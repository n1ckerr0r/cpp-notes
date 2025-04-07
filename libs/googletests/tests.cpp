#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "main.h"

TEST(ExpectTests, ExpectTest) {
    int a = 10;

    EXPECT_TRUE(func(a) == 2 * a);
    EXPECT_FALSE(func(a) != 2 * a);
    EXPECT_EQ(func(a), 2*a);
    EXPECT_THROW(func(std::numeric_limits<int>::max()/2 + 1), std::runtime_error);
}

TEST(StreamTests, StreamTest) {
    int a = 10;

    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    func1(a);
    std::cout.rdbuf(old_cout);

    EXPECT_EQ(buffer.str(), "result: 10");
}

TEST(ContainerTests, ContainerTest) {
    std::vector<int> container{0, 1, 2, 3, 4, 5};

    ASSERT_THAT(container, ::testing::ElementsAre(0, 1, 2, 3, 4, 5));
    ASSERT_THAT(container, ::testing::UnorderedElementsAre(4, 5, 0, 1, 2, 3));
}