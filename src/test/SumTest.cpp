#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../main/sum/sum.hpp"

TEST(MyFirstTest, SumTest){
    int aa = 1;
    int b = 2;
    int c = 3;
    int d = aa + b + c;
    ASSERT_EQ(sum(aa, b, c), d);
}
