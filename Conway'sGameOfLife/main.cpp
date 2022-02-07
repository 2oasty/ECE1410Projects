#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <thread>
#include <vector>

void openFile(std::string const& input, std::string const& output, std::ifstream& fin, std::ofstream& fout);

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

	return 0;
}

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