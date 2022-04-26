
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

}