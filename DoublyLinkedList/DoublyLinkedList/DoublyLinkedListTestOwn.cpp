
#include <gtest/gtest.h>

#include "DoublyLinkedList.hpp"

TEST(StudentWrittenTests, EmptyList)
{
	DoublyLinkedList<int> list;
	EXPECT_EQ(list.size(), 0);
	EXPECT_THROW(list.retreive(5), std::runtime_error);
	EXPECT_THROW(list.update(1, 2), std::runtime_error);
	EXPECT_THROW(list.remove(3), std::runtime_error);
}

TEST(StudentWrittenTests, OneNode)
{
	DoublyLinkedList<int> list;
	list.create(5);
	EXPECT_EQ(list.size(), 1);

	EXPECT_EQ(list.retreive(5), 5);
	EXPECT_THROW(list.retreive(1), std::runtime_error);

	EXPECT_THROW(list.update(3, 7), std::runtime_error);

	list.update(5, 7);
	EXPECT_EQ(list.retreive(7), 7);
	EXPECT_THROW(list.retreive(5), std::runtime_error);
	EXPECT_EQ(list.size(), 1);

	EXPECT_THROW(list.remove(3), std::runtime_error);
	list.remove(7);
	EXPECT_EQ(list.size(), 0);
	EXPECT_THROW(list.retreive(7), std::runtime_error);
}

TEST(StudentWrittenTests, Duplicates)
{
	DoublyLinkedList<int> list;
	list.create(3);
	list.create(6);
	list.create(3);
	list.create(4);
	EXPECT_EQ(list.size(), 4);

	list.update(3, 6);
	EXPECT_EQ(list.size(), 4);
	EXPECT_THROW(list.retreive(3), std::runtime_error);
	EXPECT_EQ(list.retreive(6), 6);

	list.remove(6);
	EXPECT_EQ(list.size(), 3);
	list.remove(6);
	EXPECT_EQ(list.size(), 2);
	list.remove(6);
	EXPECT_EQ(list.size(), 1);
}

TEST(StudentWrittenTests, AllTestInt)
{
	DoublyLinkedList<int> list;
	list.create(4);
	list.create(-7);
	list.create(0);
	list.create(-3);
	list.create(11);
	EXPECT_EQ(list.size(), 5);

	EXPECT_THROW(list.update(1, 2), std::runtime_error);
	list.update(4, 5);
	list.update(-3, 0);

	EXPECT_THROW(list.retreive(4), std::runtime_error);
	EXPECT_EQ(list.retreive(5), 5);
	EXPECT_THROW(list.retreive(-3), std::runtime_error);

	list.remove(0);
	EXPECT_EQ(list.size(), 4);
	EXPECT_EQ(list.retreive(0), 0);

	list.remove(5);
	list.remove(-7);
	list.remove(11);
	list.remove(0);
	EXPECT_EQ(list.size(), 0);
}