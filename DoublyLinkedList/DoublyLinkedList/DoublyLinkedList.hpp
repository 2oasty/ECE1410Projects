#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <memory>
#include <stdexcept>

template <typename T>
class DoublyLinkedList
{
public:
	
	struct Node {
		T data;
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> prev;
	};

	// DoublyLinkedList<T>();
	DoublyLinkedList<T>() : head(nullptr), tail(nullptr)
	{

	}

	//createNode
	std::shared_ptr<Node> createNode(T value)
	{
		//!!!Need to allocate as smart pointer!!!
		std::shared_ptr<Node> newNode(new Node);
		newNode->data = value;
		newNode->prev = nullptr;
		newNode->next = nullptr;
		return newNode;
	}

	//void create(T value)
	void create(T value)
	{
		std::shared_ptr<Node> newNode = createNode(value);

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			return;
		}

		head->prev = newNode;
		newNode->next = head;
		tail = head;
		head = newNode;
	}

	// T retreive(T value)
	T retreive(T value)
	{
		T temp = value;
		return temp;
	}

	//void update(T oldValue, T newValue)
	void update(T oldValue, T newValue)
	{

	}

	// void remove(T value)
	void remove(T value)
	{

	}

	//size_t size()
	size_t size()
	{
		return 5;
	}

private:
	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;

};

#endif