#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

struct MyStruct
{
	double totalCount = 0;
	int letterCount[52] = {0};
	char letters[52];
};

void openFile(std::ifstream& fin, std::ofstream& fout);
void count(MyStruct& info, std::ifstream& fin);
void printResult(MyStruct& info, std::ofstream& fout);

/******************************************************************************
* Function Title: main
*
* Summary: Calls functions to read a file, count the number of each letter,
*		   and print the letters, their count, and percentages to another file
* 
* Inputs: None
* Outputs: None
*******************************************************************************
* Pseudocode:
* 
* Begin
*	Declare fin and fout variables
*	Declare structure
*	Call openFile function
*	Call count function
*	Call printResult function
* End
******************************************************************************/

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	openFile(fin, fout);
	
	MyStruct info;
	count(info, fin);

	printResult(info, fout);

	return 0;
}



/******************************************************************************
* Function Title: openFile
*
* Summary: Opens the input and output files for reading and writing
*
* Inputs: fin (file to read from), fout (file to write to)
* Outputs: None
*******************************************************************************
* Pseudocode:
*
* Begin
*	Declare strings
*	Print instructions to enter input file name
*	Scan user input into string variable
*	Open input file
*	If input file is invalid
*	Then
*		Print error message
*		Exit program
*	EndIf
*	Print instructions to enter output file name
*	Scan user input into string variable
*	Open output file
* End
******************************************************************************/

void openFile(std::ifstream& fin, std::ofstream& fout)
{
	std::string inputFileName, outputFileName;

	std::cout << "Enter file to read from: ";
	std::cin >> inputFileName;
	fin.open(inputFileName);

	if (!fin.good())
	{
		std::cout << "File doesn't exist, exiting." << std::endl;
		exit(1);
	}
	
	std::cout << "Enter file to print to: ";
	std::cin >> outputFileName;
	fout.open(outputFileName);
}



/******************************************************************************
* Function Title: count
*
* Summary: Counts the number of each letter in the input file and puts the
*		   number of each into their respective array elements. Also counts
*		   the total number of letters in the file
*
* Inputs: info (structure containing total number of letters, an array of 
*		  the letters, and an array of the number of each letter), fin (file
*		  to read from)
* Outputs: None
*******************************************************************************
* Pseudocode:
*
* Begin
*	Loop until EOF
*		Get a line from the file
*		Test all letters from A-Z and a-z
*		Ensure that the character being tested is a letter
*		Assign current character to letter array in structure
*		Look through line one letter at a time
*		If letter is the same as character
*		Then
*			Increment count for that letter
*			Increment total count
*		EndIf
*	EndLoop
* End
******************************************************************************/

void count(MyStruct& info, std::ifstream& fin)
{
	std::string line;
	
	while (!fin.eof()) 
	{
		//One line examined at a time
		std::getline(fin, line);

		int j = 0;

		for (char ch = 'A'; ch <= 'z'; ch++)
		{
			//Only looks through line if ch is a letter
			if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			{
				info.letters[j] = ch;
				//Looks through single line
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] == ch)
					{
						info.letterCount[j]++;
						info.totalCount++;
					}
				}
				j++;
			}
		}
	}
}



/******************************************************************************
* Function Title: printResult
*
* Summary: Prints info from the structure to the output file
*
* Inputs: info (structure containing letter info), fout (file to write to)
* Outputs: None
*******************************************************************************
* Pseudocode:
*
* Begin
*	Loop for all letters
*		Print the letter
*		Print the letter's count
*		Print the percentage of the letter
*	EndLoop
* End
******************************************************************************/

void printResult(MyStruct& info, std::ofstream& fout)
{
	fout << "Letter  Count  Percentage" << std::endl;

	for (int i = 0; i < 52; i++)
	{
		fout << std::setw(4) << info.letters[i];
		fout << std::setw(7) << info.letterCount[i];
		fout << std::setw(11) << std::fixed << std::setprecision(2);
		if (info.totalCount == 0) 
		{
			fout << "0.00";
		}
		else
		{
			fout << (info.letterCount[i] / info.totalCount) * 100.00;
		}
		
		fout << "%" << std::endl;
	}
}