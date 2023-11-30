#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../main/sum/sum.hpp"

TEST(FIRSTTEST, SUMTEST){
    int a = 10;
    int b = 15;

    ASSERT_EQ(sum(a, b), 0);
}
