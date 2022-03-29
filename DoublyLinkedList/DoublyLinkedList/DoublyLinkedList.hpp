#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <memory>
#include <stdexcept>

template <typename T>
class DoublyLinkedList
{
public:
	
	struct Node {
		T data{};
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
		head = newNode;
	}

	// T retreive(T value)
	T retreive(T value)
	{
		T data{};

		std::shared_ptr<Node> temp = head;

		//Nothing in list
		if (temp == nullptr)
		{
			throw std::runtime_error("No values in list");
		}

		//Walk through list looking for value
		while (temp->next != nullptr)
		{
			if (temp->data == value)
			{
				data = temp->data;
				return data;
			}
			temp = temp->next;
		}
		if (temp->data == value)
		{
			data = temp->data;
			return data;
		}

		//If value is not in list
		if (temp->next == nullptr)
		{
			throw std::runtime_error("Value does not exist in list");
		}

		return data;
	}

	//void update(T oldValue, T newValue)
	void update(T oldValue, T newValue)
	{
		std::shared_ptr<Node> temp = head;

		//If list is empty
		if (temp == nullptr)
		{
			throw std::runtime_error("No values in list");
		}

		//If value isn't in list
		if (retreive(oldValue) != oldValue)
		{
			throw std::runtime_error("Old value does not exist in list");
		}

		//Value is in list
		while (temp->next != nullptr)
		{
			if (temp->data == oldValue)
			{
				temp->data = newValue;
			}

			temp = temp->next;
		}
		if (temp->data == oldValue)
		{
			temp->data = newValue;
		}
	}

	// void remove(T value)
	void remove(T value)
	{
	
	}

	//size_t size()
	size_t size()
	{
		size_t count = 1;
		std::shared_ptr<Node> temp = head;
		
		//If list is empty
		if (temp == nullptr)
		{
			count = 0;
			return count;
		}

		while (temp->next != nullptr)
		{
			count++;
			temp = temp->next;
		}

		return count;
	}

private:
	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;

};

#endif