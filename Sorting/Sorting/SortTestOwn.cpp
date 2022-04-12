
#include <gtest/gtest.h>
#include <algorithm>

#include "BigVector.hpp"

#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "MergeSort.hpp"

TEST(StudentWrittenTests, BubbleSort)
{
	std::vector<int> numbersOwn1 = { 0, 0, 0, 0 };
	std::vector<int> numbersOwn2 = { 5, -20, 8, 1000, 43, -2 };
	std::vector<int> numbersOwn3 = { 13 };

	auto ans1 = bubble::sort(numbersOwn1);
	std::sort(numbersOwn1.begin(), numbersOwn1.end());
	EXPECT_EQ(ans1, numbersOwn1);

	auto ans2 = bubble::sort(numbersOwn2);
	std::sort(numbersOwn2.begin(), numbersOwn2.end());
	EXPECT_EQ(ans2, numbersOwn2);

	auto ans3 = bubble::sort(numbersOwn3);
	std::sort(numbersOwn3.begin(), numbersOwn3.end());
	EXPECT_EQ(ans3, numbersOwn3);
}

TEST(StudentWrittenTests, SelectionSort)
{
	auto ans = selection::sort(numbers);
	EXPECT_EQ(ans, sorted);

	std::vector<int> numbersOwn1 = { 0, 0, 0, 0 };
	std::vector<int> numbersOwn2 = { -4, 7, 0, 16, -35, 589, 2, -13 };
	std::vector<int> numbersOwn3 = { -6 };

	auto ans1 = selection::sort(numbersOwn1);
	std::sort(numbersOwn1.begin(), numbersOwn1.end());
	EXPECT_EQ(ans1, numbersOwn1);

	auto ans2 = selection::sort(numbersOwn2);
	std::sort(numbersOwn2.begin(), numbersOwn2.end());
	EXPECT_EQ(ans2, numbersOwn2);

	auto ans3 = selection::sort(numbersOwn3);
	std::sort(numbersOwn3.begin(), numbersOwn3.end());
	EXPECT_EQ(ans3, numbersOwn3);
}

TEST(StudentWrittenTests, MergeSort)
{
	/*auto ans = merge::sort(numbers);
	EXPECT_EQ(ans, sorted);*/
}