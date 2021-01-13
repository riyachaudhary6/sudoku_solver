# sudoku_solver
Sudoku Solver

Sudoku:- It is a logic-based, combinational number-placement puzzle in which our objective is to fill a 9x9 grid/matrix and each of the nine 3x3 subgrids that compose the grid contain all of the digits from 1 to 9.

But nowadays, many new sudoku have been developed which include alphabet along with the numbers.

We are going to solve 9x9 grid sudoku for which we will use the algorithm of backtracking.

Functions created/used in SudokuSolver.cpp:-

⦁ bool UnassignedLocation(int SudokuMatrix[9][9], int &row, int &col):- Function to check whether the position/index is Assigned or Unassigned. If SudokuMatrix[row][col] is 0 then, this function will return true otherwise false.

⦁ bool isSafe(int SudokuMatrix[9][9], int row, int col, int num):- Function to check whether the number is safe to assign at that index or not. Basically it is based upon three functions.

⦁ bool NuminRow(int SudokuMatrix[9][9], int num, int row):- Function to check whether the number to be assigned is already present in that entire row or not. If number is there in that row then this functions return true otherwise false.

⦁ bool NuminCol(int SudokuMatrix[9][9], int num, int col):- Function to check whether the number to be assigned is already present in that entire column or not. If number is there in that column then this functions return true otherwise false.

⦁ bool NuminBox(int SudokuMatrix[9][9], int num, int StartRow, int StartCol):- Function to check whether the number to be assigned is already present in that entire 3 X 3 box or not. If number is there in that entire box then this functions return true otherwise false.

If all the above 3 functions returns false then this function returns true otherwise false.

⦁ bool SudokuSolve(int SudokuMatrix[9][9]):- Function to solve Sudoku. It checks all the necessary coditions till there is any unassigned value in grid and in the last returns value as true or false.

⦁ void printSudokuMatrix(int SudokuMatrix[9][9]):- Function to print SudokuMatrix

In main function, values of each row and column has already been assigned in which 0 denotes as unassigned location. If SudokuSolve(SudokuMatrix) is true then Solved Sudoku will be printed using printSudokuMatrix(SudokuMatrix) function. If there is no solution of Sudoku then, a message "No Solution of this Sudoku Exists" dispalyed on the output screen.
