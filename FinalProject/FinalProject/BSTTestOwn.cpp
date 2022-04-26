
#include <gtest/gtest.h>

#include "BST.hpp"

TEST(OwnWrittenTests, BSTOwn)
{
	Bst<int, int> bst;
	bst.add(42, 1);
	bst.add(24, -7);
	bst.add(56, 0);
	bst.add(13, 12);
	bst.add(26, -10);
	EXPECT_EQ(bst.at(24), -7);
	EXPECT_EQ(bst.at(26), -10);
	EXPECT_THROW(bst.at(3), std::runtime_error);
	EXPECT_EQ(bst[56], 0);
	EXPECT_EQ(bst[13], 12);
	EXPECT_THROW(bst[65], std::runtime_error);
	EXPECT_EQ(bst.size(), 5);
	bst.add(47, -13);
	EXPECT_EQ(bst.size(), 6);
	std::vector<Direction> test({Direction::LEFT, Direction::RIGHT});
	EXPECT_EQ(bst.traverse(test), -10);
	bst.update(26, -11);
	EXPECT_EQ(bst.traverse(test), -11);
	EXPECT_EQ(bst[26], -11);
	EXPECT_THROW(bst.update(5, 0), std::runtime_error);
}