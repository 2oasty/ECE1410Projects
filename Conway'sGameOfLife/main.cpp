#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <thread>
#include <vector>

void openFile(std::string const& input, std::string const& output, std::ifstream& fin, std::ofstream& fout);
void printVector(std::vector<std::vector<bool>>& myVector, std::ofstream& fout);

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

	//Reads in starting state from input file
	bool startingValue = 0;
	for (size_t i = 0; i < startingState.size(); i++) 
	{
		for (size_t j = 0; j < startingState[i].size(); j++)
		{
			fin >> startingValue;
			startingState[i][j] = startingValue;
		}
	}
	
	printVector(startingState, fout);

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
void printVector(std::vector<std::vector<bool>>& myVector, std::ofstream& fout)
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