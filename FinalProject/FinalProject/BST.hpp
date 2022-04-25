#ifndef BST_HPP
#define BST_HPP

enum class Direction
{
	LEFT,
	RIGHT
};

template <typename Key, typename Value>
class Bst
{
public:



	Bst();

	//Copy constructor
	Bst(Bst const& bst);

	//Add
	void add(Key const& key, Value const& value);

	//Update
	void update(Key const& key, Value const& value);
	
	//Remove
	void remove(Key const& key);

	//At
	Value& at(Key const& key);

	//Operator[]
	Value& operator[](Key const& key);

	//Traverse
	Value traverse(std::vector<Direction> const& path);

	//Size
	size_t size();

private:
};

#endif