#include <iostream>

#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "MergeSort.hpp"

//Bubble Sort
std::vector<int> bubble::sort(std::vector<int> vectorToSort)
{
	for (size_t i = 0; i < vectorToSort.size() - 1; i++)
	{
		for (size_t j = 0; j < vectorToSort.size() - 1; j++)
		{
			if (vectorToSort[j] > vectorToSort[j + 1])
			{
				std::swap(vectorToSort[j], vectorToSort[j + 1]);
			}
		}
	}

	return vectorToSort;
}

//Selection Sort
std::vector<int> selection::sort(std::vector<int> vectorToSort)
{
 	size_t smallest = 0;

	for (size_t i = 0; i < vectorToSort.size(); i++)
	{
		smallest = i;

		//Determines location of smallest number in array
		for (size_t j = i; j < vectorToSort.size() - 1; j++)
		{
			if (vectorToSort[smallest] > vectorToSort[j + 1])
			{
				smallest = j + 1;
			}
		}

		std::swap(vectorToSort[i], vectorToSort[smallest]);
	}

	return vectorToSort;
}

//Merge Sort
std::vector<int> merge::sort(std::vector<int> vectorToSort)
{
	std::vector<int> mergedVector(vectorToSort.size());

	//Terminating case
	if (vectorToSort.size() == 1 || vectorToSort.size() == 0)
	{
		return vectorToSort;
	}

	size_t middle = (vectorToSort.size() / 2) - 1;

	size_t sizeOfLeft = middle + 1;

	size_t sizeOfRight = vectorToSort.size() - (middle + 1);

	std::vector<int> left(sizeOfLeft);
	std::vector<int> right(sizeOfRight);

	for (size_t i = 0; i < vectorToSort.size(); i++)
	{
		if (i <= middle)
		{
			left[i] = vectorToSort[i];
		}

		else if (i > middle)
		{
			right[i - middle - 1] = vectorToSort[i];
		}
	}

	left = merge::sort(left);
	right = merge::sort(right);

	size_t leftItr, rightItr, mergedVectorItr;
	leftItr = 0;
	rightItr = 0;
	mergedVectorItr = 0;

	while ((leftItr < sizeOfLeft) && (rightItr < sizeOfRight))
	{
		if (left[leftItr] <= right[rightItr])
		{
			mergedVector[mergedVectorItr] = left[leftItr];
			leftItr++;
		}
		else
		{
			mergedVector[mergedVectorItr] = right[rightItr];
			rightItr++;
		}

		mergedVectorItr++;
	}

	while (leftItr < sizeOfLeft)
	{
		mergedVector[mergedVectorItr] = left[leftItr];
		leftItr++;
		mergedVectorItr++;
	}

	while (rightItr < sizeOfRight)
	{
		mergedVector[mergedVectorItr] = right[rightItr];
		rightItr++;
		mergedVectorItr++;
	}

	return mergedVector;
}