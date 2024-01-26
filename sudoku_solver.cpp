#include <iostream>

using namespace std;

// N is the size of the 2D matrix n*n
#define n 9


void print(int arr[n][n])
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << "   ";
		cout << endl;
	}
}

// Checks whether it will be legal to assign num to the given row, col
bool isSafe(int grid[n][n], int row, 
					int col, int num)
{
	
	
	for (int x = 0; x <= 8; x++)
		if (grid[row][x] == num)
			return false;

	
	for (int x = 0; x <= 8; x++)
		if (grid[x][col] == num)
			return false;

	
	int startRow = row - row % 3, 
			startCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i + startRow][j + 
							startCol] == num)
				return false;

	return true;
}


bool solveSudoku(int grid[n][n], int row, int col)
{


	if (row == n - 1 && col == n)
		return true;

	
	if (col == n) {
		row++;
		col = 0;
	}


	if (grid[row][col] > 0)
		return solveSudoku(grid, row, col + 1);

	for (int num = 1; num <= n; num++) 
	{
		
	
		if (isSafe(grid, row, col, num)) 
		{
			
	
			grid[row][col] = num;
			if (solveSudoku(grid, row, col + 1))
				return true;
		}

		grid[row][col] = 0;
	}
	return false;
}


int main()
{
	// 0 means unassigned cells
	

    int grid[n][n];

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<"The input is for row "<<i+1<<" and column "<<j+1<<":- ";
            cin>>grid[i][j];
            cout<<endl;
        }

    }
    cout<<endl;


	if (solveSudoku(grid, 0, 0)) {
        cout<<"*** Solution  **"<<endl;
		print(grid);
    }
	else
		cout << "no solution exists " << endl;

	return 0;
	
}
