#include <iostream>

#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "MergeSort.hpp"

//Bubble Sort
std::vector<int> bubble::sort(std::vector<int> vectorToSort)
{
	for (int i = 0; i < vectorToSort.size() - 1; i++)
	{
		for (int j = 0; j < vectorToSort.size() - 1; j++)
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
 	int smallest = 0;

	for (int i = 0; i < vectorToSort.size(); i++)
	{
		smallest = i;

		//Determines location of smallest number in array
		for (int j = i; j < vectorToSort.size() - 1; j++)
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
	return vectorToSort;
}