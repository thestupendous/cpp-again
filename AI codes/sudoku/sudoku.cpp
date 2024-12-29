// built from help from AI assistant (llama 3.2 version, installed
//  on local machine, 2GB wala)

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;
int board[SIZE][SIZE];

bool isValidMove(int row, int col, int num)
{
    // Check the row
    for (int i = 0; i < SIZE; i++)
    {
        if (board[row][i] == num)
            return false;
    }

    // Check the column
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][col] == num)
            return false;
    }

    // Check the box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[boxRow + i][boxCol + j] == num)
                return false;
        }
    }

    // If we reach here, the move is valid
    return true;
}

bool solveSudoku()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (board[row][col] == 0)
            { // empty cell
                for (int num = 1; num <= SIZE; num++)
                {
                    if (isValidMove(row, col, num))
                    {
                        board[row][col] = num;
                        if (solveSudoku())
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << board[row][col] << " ";
            if (col % 3 == 2 && col != SIZE - 1)
                cout << "|";
        }
        cout << endl;
        if (row % 3 == 2 && row != SIZE - 1)
            cout << "-+---+---+---+---+---+---+--\n";
    }
}

int main()
{
    int tempBoard[SIZE][SIZE] = {
        {0, 0, 7, 0, 0, 0, 0, 8, 4},
        {1, 0, 0, 6, 0, 4, 2, 0, 7},
        {9, 5, 4, 0, 0, 2, 0, 0, 0},
        {7, 0, 0, 4, 6, 0, 0, 3, 0},
        {0, 3, 0, 2, 0, 1, 0, 4, 5},
        {0, 2, 8, 0, 3, 0, 0, 9, 0},
        {5, 4, 1, 0, 2, 0, 0, 0, 0},
        {8, 0, 0, 3, 0, 0, 0, 6, 1},
        {3, 0, 0, 0, 5, 8, 0, 2, 9}};

    memcpy(board, tempBoard, sizeof(tempBoard));

    if (!solveSudoku())
        cout << "No solution exists!" << endl;
    printBoard();

    return 0;
}