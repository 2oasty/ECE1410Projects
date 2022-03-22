
#include <gtest/gtest.h>

#include "ImaginaryNumber.hpp"

// Default constructor
TEST(StudentWrittenTests, DefaultConstructor)
{
	ImaginaryNumber num;
	EXPECT_EQ(num.getReal(), 0);
	EXPECT_EQ(num.getImaginary(), 0);
}

// +=
TEST(StudentWrittenTests, AddEqual)
{
	ImaginaryNumber lhs1(0, 0);
	ImaginaryNumber lhs2(-8, -1);
	ImaginaryNumber lhs3(0, 0);
	ImaginaryNumber lhs4(-8, -1);
	ImaginaryNumber rhs1(0, 0);
	ImaginaryNumber rhs2(-5, -6);
	ImaginaryNumber rhs3(-5, -6);
	ImaginaryNumber rhs4(10, 4);
	EXPECT_EQ(lhs1 += rhs1, ImaginaryNumber(0, 0));
	EXPECT_EQ(lhs2 += rhs2, ImaginaryNumber(-13, -7));
	EXPECT_EQ(lhs3 += rhs3, ImaginaryNumber(-5, -6));
	EXPECT_EQ(lhs4 += rhs4, ImaginaryNumber(2, 3));
}

// +
TEST(StudentWrittenTests, Add)
{
	ImaginaryNumber lhs1(0, 0);
	ImaginaryNumber lhs2(-8, -1);
	ImaginaryNumber rhs1(0, 0);
	ImaginaryNumber rhs2(-5, -6);
	ImaginaryNumber rhs3(10, 4);
	EXPECT_EQ(lhs1 + rhs1, ImaginaryNumber(0, 0));
	EXPECT_EQ(lhs2 + rhs2, ImaginaryNumber(-13, -7));
	EXPECT_EQ(lhs1 + rhs2, ImaginaryNumber(-5, -6));
	EXPECT_EQ(lhs2 + rhs3, ImaginaryNumber(2, 3));
}

// -=
TEST(StudentWrittenTests, SubtractEqual)
{
	ImaginaryNumber lhs1(0, 0);
	ImaginaryNumber lhs2(-5, -7);
	ImaginaryNumber lhs3(-5, -7);
	ImaginaryNumber lhs4(3, 6);
	ImaginaryNumber rhs1(0, 0);
	ImaginaryNumber rhs2(-7, -10);
	ImaginaryNumber rhs3(0, 0);
	ImaginaryNumber rhs4(-7, -10);
	EXPECT_EQ(lhs1 -= rhs1, ImaginaryNumber(0, 0));
	EXPECT_EQ(lhs2 -= rhs2, ImaginaryNumber(2, 3));
	EXPECT_EQ(lhs3 -= rhs3, ImaginaryNumber(-5, -7));
	EXPECT_EQ(lhs4 -= rhs4, ImaginaryNumber(10, 16));
}

// -
TEST(StudentWrittenTests, Subtract)
{
	ImaginaryNumber lhs1(0, 0);
	ImaginaryNumber lhs2(-5, -7);
	ImaginaryNumber lhs3(3, 6);
	ImaginaryNumber rhs1(0, 0);
	ImaginaryNumber rhs2(-7, -10);
	EXPECT_EQ(lhs1 - rhs1, ImaginaryNumber(0, 0));
	EXPECT_EQ(lhs2 - rhs2, ImaginaryNumber(2, 3));
	EXPECT_EQ(lhs2 - rhs1, ImaginaryNumber(-5, -7));
	EXPECT_EQ(lhs3 - rhs2, ImaginaryNumber(10, 16));
}

// *=
TEST(StudentWrittenTests, MultiplyEqual)
{
	ImaginaryNumber lhs1(0, 0);
	ImaginaryNumber lhs2(3, 2);
	ImaginaryNumber lhs3(3, 2);
	ImaginaryNumber lhs4(-6, -1);
	ImaginaryNumber rhs1(0, 0);
	ImaginaryNumber rhs2(0, 0);
	ImaginaryNumber rhs3(-5, 2);
	ImaginaryNumber rhs4(-5, 2);
	EXPECT_EQ(lhs1 *= rhs1, ImaginaryNumber(0, 0));
	EXPECT_EQ(lhs2 *= rhs2, ImaginaryNumber(0, 0));
	EXPECT_EQ(lhs3 *= rhs3, ImaginaryNumber(-19, -4));
	EXPECT_EQ(lhs4 *= rhs4, ImaginaryNumber(32, -7));
}

// *
TEST(StudentWrittenTests, Multiply)
{
	ImaginaryNumber lhs1(0, 0);
	ImaginaryNumber lhs2(3, 2);
	ImaginaryNumber lhs3(-6, -1);
	ImaginaryNumber rhs1(0, 0);
	ImaginaryNumber rhs2(-5, 2);
	EXPECT_EQ(lhs1 * rhs1, ImaginaryNumber(0, 0));
	EXPECT_EQ(lhs2 * rhs1, ImaginaryNumber(0, 0));
	EXPECT_EQ(lhs2 * rhs2, ImaginaryNumber(-19, -4));
	EXPECT_EQ(lhs3 * rhs2, ImaginaryNumber(32, -7));
}

// >
TEST(StudentWrittenTests, Greater)
{
	ImaginaryNumber lhs1(1, 3);
	ImaginaryNumber rhs1(2, 2);
	ImaginaryNumber rhs2(3, 4);
	ImaginaryNumber rhs3(3, 1);
	ImaginaryNumber rhs4(-5, -1);
	EXPECT_EQ(lhs1 > rhs1, true);
	EXPECT_EQ(lhs1 > rhs2, false);
	EXPECT_EQ(lhs1 > rhs3, false);
	EXPECT_EQ(lhs1 > rhs4, false);
}

// >=
TEST(StudentWrittenTests, GreaterEqual)
{
	ImaginaryNumber lhs1(1, 3);
	ImaginaryNumber rhs1(2, 2);
	ImaginaryNumber rhs2(3, 4);
	ImaginaryNumber rhs3(3, 1);
	ImaginaryNumber rhs4(-3, -1);
	EXPECT_EQ(lhs1 >= rhs1, true);
	EXPECT_EQ(lhs1 >= rhs2, false);
	EXPECT_EQ(lhs1 >= rhs3, true);
	EXPECT_EQ(lhs1 >= rhs4, true);
}

// ==
TEST(StudentWrittenTests, EqualEqual)
{
	ImaginaryNumber lhs1(2, 4);
	ImaginaryNumber rhs1(2, 4);
	ImaginaryNumber rhs2(4, 2);
	ImaginaryNumber rhs3(-2, -4);
	ImaginaryNumber rhs4(0, 0);
	EXPECT_EQ(lhs1 == rhs1, true);
	EXPECT_EQ(lhs1 == rhs2, true);
	EXPECT_EQ(lhs1 == rhs3, true);
	EXPECT_EQ(lhs1 == rhs4, false);
}