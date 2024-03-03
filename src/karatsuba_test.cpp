#include <karatsuba.h>
#include <gtest/gtest.h>


TEST(karatsuba, BothPositive) {
    int a = 15, b = 34;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 1239, b = 6549;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 1, b = 12;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 12, b = 1;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 0, b = 5;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 178, b = 2;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
}

TEST(karatsuba, BothNegative) {
    int a = -15, b = -34;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = -1239, b = -6549;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = -1, b = -12;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = -12, b = -1;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = -10, b = -5;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = -178, b = -2;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
}

TEST(karatsuba, OneNegative) {
    int a = -15, b = 34;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 1239, b = -6549;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 1, b = -12;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = -12, b = 1;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 10, b = -5;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
     a = 178, b = -2;
    EXPECT_EQ(karatsubaMul(a, b), a*b);
}