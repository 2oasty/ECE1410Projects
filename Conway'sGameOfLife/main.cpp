#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <thread>
#include <vector>

void openFile(std::string const& input, std::string const& output,
			  std::ifstream& fin, std::ofstream& fout);
void readStartingState(std::vector<std::vector<bool>>& myVector,
					   std::ifstream& fin);
void printVector(std::vector<std::vector<bool>>const& myVector,
				 std::ofstream& fout);
uint64_t countAliveNeighbors(std::vector<std::vector<bool>>const& myVector,
							 int& i, int& j, int const& width,
							 int const& height);
void evaluateState(std::vector<std::vector<bool>>& startingState,
				   std::vector<std::vector<bool>>& newState, int const& width,
				   int const& height, int const& rounds);

/******************************************************************************
* Function Title: main
* 
* Summary: Takes in an input and output file for Conway's game of life. Takes
*		   initial state of tiles and prints tile changes after each round to
*		   the screen and the final result to the output file
* 
* Inputs: argc (number of arguments), argv (names of arguments)
* Outputs: None
*******************************************************************************
* Pseudocode:
* 
* Begin
*	Assign two file name arguments to string variables
*	Call openFile function, passing in strings
*	Scan width, height, and rounds properties from the input file
*	Call readStartingState function
*	Call evaluateState function
*	Call printVector function (print final result to output file)
*	Close input and output files
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

	std::vector<std::vector<bool>> startingState(height,
												 std::vector<bool>(width));

	readStartingState(startingState, fin);

	//Copies startingState into newState
	std::vector<std::vector<bool>> newState(height, std::vector<bool>(width));
	newState = startingState;

	evaluateState(startingState, newState, width, height, rounds);

	printVector(newState, fout);

	fin.close();
	fout.close();

	return 0;
}


/******************************************************************************
* Function Title: openFile
*
* Summary: Opens input and output files for reading and writing
*
* Inputs: input (input file string from command line), 
*		  output (output file string from command line), fin (input file), 
*		  fout (output file)
* Outputs: None
*******************************************************************************
* Pseudocode:
*
* Begin
*	Pass in strings from command line
*	Open input file
*	If input file doesn't exist
*	Then
*		Print error message
*		Exit program
*	EndIf
*	Open output file
* End
******************************************************************************/
void openFile(std::string const& input, std::string const& output,
			  std::ifstream& fin, std::ofstream& fout) 
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
* Summary: Scans the starting state from the input file and puts it into
*		   a vector
*
* Inputs: myVector (vector that holds starting state), fin (input file)
* Outputs: None
*******************************************************************************
* Pseudocode:
*
* Begin
*	Loop for height
*		Loop for width
*			Scan in bool value from input file
*			Put bool value in vector
*		EndLoop
*	EndLoop
* End
******************************************************************************/
void readStartingState(std::vector<std::vector<bool>>& myVector,
					   std::ifstream& fin)
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
* Summary: Prints vector to output file
*
* Inputs: myVector (vector to be printed), fout (output file)
* Outputs: None
*******************************************************************************
* Pseudocode:
*
* Begin
*	Loop for height
*		Loop for width
*			If current vector index is false
*			Then
*				Print space to the output file
*			Else
*				Print lowercase o to the output file
*			EndIf
*		EndLoop
*		Print endl
*	EndLoop
* End
******************************************************************************/
void printVector(std::vector<std::vector<bool>>const& myVector,
				 std::ofstream& fout)
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
* Function Title: countAliveNeighbors
*
* Summary: Looks at all neighbors of a certain tile and counts all neighbors
*		   that hold a true value
*
* Inputs: myVector (vector to be evaluated), i (current row), j (current
*		  column), width (width from input file), height (height from
*		  input file)
* Outputs: aliveNeighbors (unsigned int that represents total number of
*		   alive neighbors for a tile)
*******************************************************************************
* Pseudocode:
*
* Begin
*	Check that neighbors are valid (meaning they exist inside the vector)
*	If the neighbor is valid
*	Then
*		If the neighbor has a true value
*		Then
*			Increment counter
*		EndIf
*	EndIf
*	Return counter
* End
******************************************************************************/
uint64_t countAliveNeighbors(std::vector<std::vector<bool>>const& myVector,
	int& i, int& j, int const& width,
	int const& height)
{
	uint64_t aliveNeighbors = 0;

	//top left
	if (i - 1 >= 0 && j - 1 >= 0)
	{
		if (myVector[i - 1][j - 1] == 1)
		{
			aliveNeighbors++;
		}
	}

	//top
	if (i - 1 >= 0)
	{
		if (myVector[i - 1][j] == 1)
		{
			aliveNeighbors++;
		}
	}

	//top right
	if (i - 1 >= 0 && j + 1 < width)
	{
		if (myVector[i - 1][j + 1] == 1)
		{
			aliveNeighbors++;
		}
	}

	//left
	if (j - 1 >= 0)
	{
		if (myVector[i][j - 1] == 1)
		{
			aliveNeighbors++;
		}
	}

	//right
	if (j + 1 < width)
	{
		if (myVector[i][j + 1] == 1)
		{
			aliveNeighbors++;
		}
	}

	//bottom left
	if (i + 1 < height && j - 1 >= 0)
	{
		if (myVector[i + 1][j - 1] == 1)
		{
			aliveNeighbors++;
		}
	}

	//bottom
	if (i + 1 < height)
	{
		if (myVector[i + 1][j] == 1)
		{
			aliveNeighbors++;
		}
	}

	//bottom right
	if (i + 1 < height && j + 1 < width)
	{
		if (myVector[i + 1][j + 1] == 1)
		{
			aliveNeighbors++;
		}
	}

	return aliveNeighbors;
}


/******************************************************************************
* Function Title: evaluateState
*
* Summary: Checks each tile, either killing or resurrecting them. Prints each
		   stage to the screen, pausing for 100 milliseconds between each round
*
* Inputs: startingState (first state vector and reference), newState (vector
*		  altered to reflect tile changes), width (width from input file),
*		  height (height from input file), rounds (rounds from input file)
* Outputs: None
*******************************************************************************
* Pseudocode:
*
* Begin
*	Loop for rounds
*		Loop for height
*			Loop for width
*				If tile is dead
*				Then
*					If 3 neighbors are alive
*					Then
*						Resurrect tile.
*					Else
*						Tile stays dead
*					EndIf
*				Else
*					If 2 or 3 neighbors are alive
*					Then
*						Keep tile alive
*					Else
*						Kill tile
*					EndIf
*				EndIf
*			EndLoop
*		EndLoop
*		Loop for height
*			Loop for width
*				If current index is false
*				Then
*					Print space to screen
*				Else
*					Print lowercase o to screen
*				EndIf
*			EndLoop
*			Print endl
*		EndLoop
*		Pause for 100 milliseconds
*	EndLoop
* End
******************************************************************************/
void evaluateState(std::vector<std::vector<bool>>& startingState,
	std::vector<std::vector<bool>>& newState, int const& width,
	int const& height, int const& rounds)
{
	for (int k = 0; k < rounds; k++)
	{
		for (int i = 0; i < startingState.size(); i++)
		{
			for (int j = 0; j < startingState[i].size(); j++)
			{
				//If tile is dead
				if (startingState[i][j] == 0)
				{
					if (countAliveNeighbors(startingState, i, j, width,
						height) == 3)
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
					if (countAliveNeighbors(startingState, i, j, width,
						height) == 2 || countAliveNeighbors(startingState,
							i, j, width, height) == 3)
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
		for (size_t i = 0; i < newState.size(); i++)
		{
			for (size_t j = 0; j < newState[i].size(); j++)
			{
				if (newState[i][j] == 0)
				{
					std::cout << "  ";
				}
				else
				{
					std::cout << "o ";
				}
			}
			std::cout << std::endl;
		}
		startingState = newState;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
