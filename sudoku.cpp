#include<bits/stdc++.h>
using namespace std;

//Function to check whether the number to be assigned is already present in that entire row or not/
bool NuminRow(int SudokuMatrix[9][9], int num, int row)
{
	int a=0;
	for(int col=0; col<9; col++)
		if(SudokuMatrix[row][col]==num)
			return true;
	return false;		
}

//Function to check whether the number to be assigned is already present in that entire column or not/
bool NuminCol(int SudokuMatrix[9][9], int num, int col)
{
	for(int row=0; row<9; row++)
		if(SudokuMatrix[row][col]==num)
			return true;
	return false;		
}

//Function to check whether the number to be assigned is already present in that entire 3 X 3 box or not/
bool NuminBox(int SudokuMatrix[9][9], int num, int StartRow, int StartCol)
{
	for(int row=0; row<3; row++)
		for(int col=0; col<3; col++)
			if(SudokuMatrix[row+StartRow][col+StartCol]==num)
				return true;
	return false;		
}

//Function to check whether the number is safe to assign at that index/
bool isSafe(int SudokuMatrix[9][9], int row, int col, int num)
{
	return !NuminRow(SudokuMatrix, num, row) && !NuminCol(SudokuMatrix, num, col) && !NuminBox(SudokuMatrix, num, row-row%3, col-col%3);
}

//Function to check whether the position/index is Assigned or Unassigned/
bool UnassignedLocation(int SudokuMatrix[9][9], int &row, int &col)
{
	for(row=0; row<9; row++)
		for(col=0; col<9; col++)
			if(SudokuMatrix[row][col]==0)
				return true;
	return false;			
}

//Function to solve Sudoku/
bool SudokuSolve(int SudokuMatrix[9][9])
{
	int row,col;
	if(!UnassignedLocation(SudokuMatrix, row, col))
		return true;
	for(int num=1; num<10; num++)
		if(isSafe(SudokuMatrix, row, col, num))	
		{
			SudokuMatrix[row][col]=num;
			if(SudokuSolve(SudokuMatrix))
				return true;
			SudokuMatrix[row][col]=0;	
		}
	return false;	 
}

//Function to print SudokuMatrix/
void printSudokuMatrix(int SudokuMatrix[9][9])
{
	for(int row=0; row<9; row++)
	{
		for(int col=0; col<9; col++)
			cout<<SudokuMatrix[row][col]<<" ";
		cout<<"\n";
	}
}

int main()
{
	int SudokuMatrix[9][9] = {{0, 5, 0, 3, 1, 4, 0, 6, 0},
					  		  {8, 7, 0, 0, 0, 9, 4, 0, 3},
					  		  {6, 4, 3, 5, 0, 7, 1, 9, 2},
					  		  {0, 0, 7, 8, 0, 5, 2, 1, 0},
					  		  {4, 1, 0, 9, 0, 0, 0, 0, 0},
					  	   	  {0, 2, 5, 0, 6, 1, 9, 0, 7},
					  		  {7, 9, 0, 2, 5, 0, 8, 4, 0},
					  		  {0, 0, 4, 0, 9, 6, 0, 0, 5},
					  		  {0, 3, 0, 1, 0, 8, 6, 7, 0}};	
	if(SudokuSolve(SudokuMatrix)==true)
		printSudokuMatrix(SudokuMatrix);
	else
		cout<<"No Solution of this Sudoku Exists"<<endl;	
	return 0;	
}
