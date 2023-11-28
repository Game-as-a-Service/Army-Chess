#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../main/sum.hpp"

TEST(FIRSTTEST, SUMTEST){
    int a = 10;
    int b = 20;

    ASSERT_EQ(sum(a, b), a + b);
}
