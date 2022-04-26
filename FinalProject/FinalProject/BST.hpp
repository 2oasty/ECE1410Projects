#ifndef BST_HPP
#define BST_HPP

#include <memory>
#include <stdexcept>
#include <vector>

enum class Direction
{
	LEFT,
	RIGHT
};

template <typename Key, typename Value>
class Bst
{
public:

	struct Node {
		Key key{};
		Value value{};
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
	};

	//Default constructor
	Bst() : head(nullptr)
	{

	}

	//Copy constructor
	Bst(Bst const& bst)
	{

	}

	//createNode
	std::shared_ptr<Node> createNode(Key const& key, Value const& value)
	{
		std::shared_ptr<Node> newNode = std::make_shared<Node>();
		newNode->key = key;
		newNode->value = value;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}

	//Add (logn or n)
	void add(Key const& key, Value const& value)
	{
		addRec(head, key, value);
	}

	//Recursive add
	void addRec(std::shared_ptr<Node> &temp, Key const& key, Value const& value)
	{
		//Nothing in BST
		if (temp == nullptr)
		{
			temp = createNode(key, value);
			return;
		}

		//Key already exists
		if (key == temp->key)
		{
			return;
		}

		//Nodes exist in BST
		if (key < temp->key)
		{
			addRec(temp->left, key, value);
		}
		else if (key > temp->key)
		{
			addRec(temp->right, key, value);
		}
	}

	//Update
	void update(Key const& key, Value const& value)
	{
		std::shared_ptr<Node> temp = head;

		while (temp != nullptr)
		{
			if (key == temp->key)
			{
				temp->value = value;
				return;
			}
			else if (key < temp->key)
			{
				temp = temp->left;
			}
			else if (key > temp->key)
			{
				temp = temp->right;
			}
		}

		throw std::runtime_error("Node doesn't exist in BST");

	}
	
	//Remove
	void remove(Key const& key)
	{
		walkThru(head, key);
		std::shared_ptr<Node> temp = nullptr;

		//Node has no children or one child
		if (head->right == nullptr)
		{
			head = head->left;
		}
		else if (head->left == nullptr)
		{
			head = head->right;
		}

		//Node has two children
		else
		{
			temp = head->left;

			while (temp->right != nullptr)
			{
				temp = temp->right;
			}

			temp->right = head->right;

			head = head->left;

		}
	}

	//At
	Value& at(Key const& key)
	{
		std::shared_ptr<Node> temp = head;

		while (temp != nullptr)
		{
			if (key == temp->key)
			{
				return temp->value;
			}
			else if (key < temp->key)
			{
				temp = temp->left;
			}
			else if (key > temp->key)
			{
				temp = temp->right;
			}
		}
		
		throw std::runtime_error("Node doesn't exist in BST");

	}

	//Operator[]
	Value& operator[](Key const& key)
	{
		return at(key);
	}

	//Traverse
	Value traverse(std::vector<Direction> const& path)
	{

		std::shared_ptr<Node> temp = head;

		for (size_t i = 0; i != path.size(); i++)
		{
			if (path[i] == Direction::LEFT)
			{
				temp = temp->left;
			}
			else if (path[i] == Direction::RIGHT)
			{
				temp = temp->right;
			}
		}

		return temp->value;
	}

	//Size
	size_t size()
	{
		size_t count = 0;

		walkThruCount(head, count);

		return count;
	}

	//Walks through all nodes
	size_t walkThruCount(std::shared_ptr<Node> temp, size_t &count)
	{

		if (temp != nullptr)
		{
			walkThruCount(temp->left, count);
			walkThruCount(temp->right, count);
			count++;
		}

		return count;
	}

	std::shared_ptr<Node> walkThru(std::shared_ptr<Node> &temp, Key const& key)
	{
		//std::shared_ptr<Node> temp = head;

		while (temp != nullptr)
		{
			if (key == temp->key)
			{
				return temp;
			}
			else if (key < temp->key)
			{
				temp = temp->left;
			}
			else if (key > temp->key)
			{
				temp = temp->right;
			}
		}

		throw std::runtime_error("Node doesn't exist in BST");

	}


private:
	std::shared_ptr<Node> head;
};

#endif