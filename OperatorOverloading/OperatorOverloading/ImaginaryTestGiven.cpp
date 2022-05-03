
#include <gtest/gtest.h>

#include <sstream>

#include "ImaginaryNumber.hpp"

TEST(GivenWrittenTests, ParamConstructor)
{
    ImaginaryNumber num(4, 5);
    ImaginaryNumber num1(0, 5);
    ImaginaryNumber num2(4, -5);
    ImaginaryNumber num3(-4, 0);
    EXPECT_EQ(num.getReal(), 4);
    EXPECT_EQ(num.getImaginary(), 5);
    EXPECT_EQ(num1.getReal(), 0);
    EXPECT_EQ(num1.getImaginary(), 5);
    EXPECT_EQ(num2.getReal(), 4);
    EXPECT_EQ(num2.getImaginary(), -5);
    EXPECT_EQ(num3.getReal(), -4);
    EXPECT_EQ(num3.getImaginary(), 0);
}

TEST(GivenWrittenTests, OStreamConstructor)
{
    {
        std::stringstream ss;
        ImaginaryNumber num(4, 5);
        ss << num;
        EXPECT_EQ(ss.str(), "4 + 5j");
    }
    {
        std::stringstream ss;
        ImaginaryNumber num(0, -5);
        ss << num;
        EXPECT_EQ(ss.str(), "-5j");
    }
    {
        std::stringstream ss;
        ImaginaryNumber num(-4, 0);
        ss << num;
        EXPECT_EQ(ss.str(), "-4");
    }
    {
        std::stringstream ss;
        ImaginaryNumber num(0, 0);
        ss << num;
        EXPECT_EQ(ss.str(), "0");
    }
}

TEST(GraderWrittenTests, Divide)
{
    ImaginaryNumber lhs(2, 2);
    ImaginaryNumber rhs1(4, 0);
    ImaginaryNumber rhs2(0, 6);
    ImaginaryNumber rhs3(5, 6);
    ImaginaryNumber rhs4(0, 0);
    EXPECT_EQ(lhs / rhs1, ImaginaryNumber(.5, .5));
    EXPECT_EQ(lhs / rhs2, ImaginaryNumber(.333333, -.333333));
    EXPECT_EQ(lhs / rhs3, ImaginaryNumber(.360655, -0.032786));
    EXPECT_EQ(lhs / rhs4, ImaginaryNumber(0, 0));
}

TEST(GraderWrittenTests, DivideEqual)
{
    ImaginaryNumber lhs1(2, 2);
    ImaginaryNumber lhs2(2, 2);
    ImaginaryNumber lhs3(2, 2);
    ImaginaryNumber lhs4(2, 2);
    ImaginaryNumber rhs1(4, 0);
    ImaginaryNumber rhs2(0, 6);
    ImaginaryNumber rhs3(5, 6);
    ImaginaryNumber rhs4(0, 0);
    EXPECT_EQ(lhs1 /= rhs1, ImaginaryNumber(.5, .5));
    EXPECT_EQ(lhs2 /= rhs2, ImaginaryNumber(.333333, -.333333));
    EXPECT_EQ(lhs3 /= rhs3, ImaginaryNumber(.360655, -0.032786));
    EXPECT_EQ(lhs4 /= rhs4, ImaginaryNumber(0, 0));
}

TEST(GraderWrittenTests, SetEqual)
{
    ImaginaryNumber rhs(2, 3);
    ImaginaryNumber lhs = rhs;

    EXPECT_EQ(lhs.getReal(), 2);
    EXPECT_EQ(lhs.getImaginary(), 3);
}

TEST(GraderWrittenTests, Less)
{
    ImaginaryNumber rhs(2, 0);
    ImaginaryNumber lhs1(2, 2);
    ImaginaryNumber lhs2(1, 1);
    ImaginaryNumber lhs3(0, 2);
    ImaginaryNumber lhs4(0, 0);
    EXPECT_EQ(rhs < lhs1, true);
    EXPECT_EQ(rhs < lhs2, false);
    EXPECT_EQ(rhs < lhs3, false);
    EXPECT_EQ(rhs < lhs4, false);
}

TEST(GraderWrittenTests, LessEqual)
{
    ImaginaryNumber rhs(2, 0);
    ImaginaryNumber lhs1(2, 2);
    ImaginaryNumber lhs2(2, 0);
    ImaginaryNumber lhs3(0, 2);
    ImaginaryNumber lhs4(0, 0);
    EXPECT_EQ(rhs <= lhs1, true);
    EXPECT_EQ(rhs <= lhs2, true);
    EXPECT_EQ(rhs <= lhs3, true);
    EXPECT_EQ(rhs <= lhs4, false);
}