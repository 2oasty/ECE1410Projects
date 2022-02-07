#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <thread>
#include <vector>

void openFile(std::string const& input, std::string const& output, std::ifstream& fin, std::ofstream& fout);
void readStartingState(std::vector<std::vector<bool>>& myVector, std::ifstream& fin);
void printVector(std::vector<std::vector<bool>>const& myVector, std::ofstream& fout);
uint64_t countAliveNeighbors(std::vector<std::vector<bool>>const& myVector, size_t const& i, size_t const& j, int const& width, int const& height);

/******************************************************************************
* Function Title: main
* 
* Summary:
* 
* Inputs:
* Outputs:
*******************************************************************************
* Pseudocode:
* 
* Begin
* End
******************************************************************************/
int main(int argc, char* argv[]) 
{
	std::string inputFile, outputFile;
	std::ifstream fin;
	std::ofstream fout;
	int width, height, rounds;

	inputFile = argv[1];
	outputFile = argv[2];
	
	openFile(inputFile, outputFile, fin, fout);

	//Scans in first number as width
	fin >> width;
	//Scans in second number as height
	fin >> height;
	//Scans in third number as rounds
	fin >> rounds;

	std::vector<std::vector<bool>> startingState(height, std::vector<bool>(width));

	readStartingState(startingState, fin);
	
	printVector(startingState, fout);




	//Copies startingState into newState
	std::vector<std::vector<bool>> newState(height, std::vector<bool>(width));
	startingState = newState;


	for (size_t i = 0; i < startingState.size(); i++)
	{
		for (size_t j = 0; j < startingState[i].size(); j++)
		{
			//If tile is dead
			if (startingState[i][j] == 0) 
			{
				if (countAliveNeighbors(startingState, i, j, width, height) == 3) 
				{
					newState[i][j] = 1;
				}
				else
				{
					newState[i][j] = 0;
				}
			}
			//If tile is alive
			else
			{
				if (countAliveNeighbors(startingState, i, j, width, height) == 2 || countAliveNeighbors(startingState, i, j, width, height) == 3)
				{
					newState[i][j] = 1;
				}
				else
				{
					newState[i][j] = 0;
				}
			}
		}
	}




	return 0;
}


/******************************************************************************
* Function Title: openFile
*
* Summary:
*
* Inputs:
* Outputs:
*******************************************************************************
* Pseudocode:
*
* Begin
* End
******************************************************************************/
void openFile(std::string const& input, std::string const& output, std::ifstream& fin, std::ofstream& fout) 
{
	//Opens input file for reading
	fin.open(input);
	if (!fin.good()) 
	{
		std::cout << "Input file doesn't exist, exiting..." << std::endl;
		exit(1);
	}

	fout.open(output);
}


/******************************************************************************
* Function Title: readStartingState
*
* Summary:
*
* Inputs:
* Outputs:
*******************************************************************************
* Pseudocode:
*
* Begin
* End
******************************************************************************/
void readStartingState(std::vector<std::vector<bool>>& myVector, std::ifstream& fin)
{
	bool startingValue = 0;
	for (size_t i = 0; i < myVector.size(); i++)
	{
		for (size_t j = 0; j < myVector[i].size(); j++)
		{
			fin >> startingValue;
			myVector[i][j] = startingValue;
		}
	}
}


/******************************************************************************
* Function Title: printVector
*
* Summary:
*
* Inputs:
* Outputs:
*******************************************************************************
* Pseudocode:
*
* Begin
* End
******************************************************************************/
void printVector(std::vector<std::vector<bool>>const& myVector, std::ofstream& fout)
{
	for (size_t i = 0; i < myVector.size(); i++)
	{
		for (size_t j = 0; j < myVector[i].size(); j++)
		{
			if (myVector[i][j] == 0)
			{
				fout << "  ";
			}
			else
			{
				fout << "o ";
			}
		}
		fout << std::endl;
	}
}


/******************************************************************************
* Function Title: countNeighbors
*
* Summary:
*
* Inputs:
* Outputs:
*******************************************************************************
* Pseudocode:
*
* Begin
* End
******************************************************************************/
uint64_t countAliveNeighbors(std::vector<std::vector<bool>>const& myVector, size_t const& i, size_t const& j, int const& width, int const& height) 
{
	uint64_t aliveNeighbors = 0;

	//top left
	if (i - 1 >= 0 && j - 1 >= 0 && myVector[i][j] == 1)
	{
		aliveNeighbors++;
	}

	//top
	if (i - 1 >= 0 && myVector[i][j] == 1)
	{
		aliveNeighbors++;
	}

	//top right
	if (i - 1 >= 0 && j + 1 < width && myVector[i][j] == 1)
	{
		aliveNeighbors++;
	}

	//left
	if (j - 1 >= 0 && myVector[i][j] == 1)
	{
		aliveNeighbors++;
	}

	//right
	if (j + 1 < width && myVector[i][j] == 1)
	{
		aliveNeighbors++;
	}

	//bottom left
	if (i + 1 < height && j - 1 >= 0 && myVector[i][j] == 1)
	{
		aliveNeighbors++;
	}

	//bottom
	if (i + 1 < height && myVector[i][j] == 1)
	{
		aliveNeighbors++;
	}

	//bottom right
	if (i + 1 < height && j + 1 < width && myVector[i][j] == 1)
	{
		aliveNeighbors++;
	}

	return aliveNeighbors;
}