// ConsoleTicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define BLANK ':'		// Which character to use for blank spaces

void printBoard(char board[3][3]);
bool isValidMove(char board[3][3], int i, int j);
bool isWinner(char board[3][3], char player);

using namespace std;

int main()
{
	char board[3][3];	// 3x3 TicTacToe board
	char player = 'X';	// Which player is taking a turn
	bool bull = true;	// Game Loop, h/t DigiPen
	char input[4];		// Input array
	int  x,				// X coordinate of input
		 y;				// Y coordinate of input

	for (int i = 0; i < 3; i++)		// Initialize gameboard
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = BLANK;
		}

	cout << "No error checking performed. It is up to the user to ensure correct input.\n";
	cout << "\'q\' to quit:\n";

	while (bull == true)		// Begin Game Loop
	{
		printBoard(board);

		cout << player << "\'s turn.";

		cin >> input;			// Input must be in the form "x,y", or "q"; all other inputs invalid and not checked

		cin.get();				// Capture newline character if necessary

		if (input[0] == 'q')	// Quit
		{
			bull = false;
			continue;
		}

		x = (input[0] - '0') - 1;			// Subtract the character 0 to return the number from the ASCII value
		y = (input[2] - '0') - 1;

		if (!isValidMove(board,x, y))		// Check if move is valid
		{
			cout << "Invalid move. Try again.\n";
			continue;
		}
		else
		{
			board[x][y] = player;
		}

		if (isWinner(board, player))		// Check if there is a winner
		{
			cout << "\n\n\n\n" << player << " wins!" << endl;
			printBoard(board);
			bull = false;
			continue;
		}

		if (player == 'X')					// Switch player at end of turn
			player = 'O';
		else if (player = 'O')
			player = 'X';
	}

	cin.get();		// Hold console window open
	
    return 1;
}

/************************************************
 * Function: isValidMove
 * Return: bool
 * Arguments: 3x3 TicTacToe board, coordinates
 * Description: Check if the selected coordinates
 *  are within bounds and have not been selected
 ************************************************/
bool isValidMove(char board[3][3], int i, int j)
{
	if (i > 3 or j > 3)
	{
		cout << "Index too large";
		return false;
	}
	else if (board[i][j] == BLANK)
	{
		return true;
	}

	return false;
}

/************************************************
* Function: isWinner
* Return: bool
* Arguments: 3x3 TicTacToe board, player
* Description: Check if the player has achieved
*  3 in a row, column, or diagonal
************************************************/
bool isWinner(char board[3][3], char player)
{
	if      (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] == player)
		return true;
	else if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] == player)
		return true;
	else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] == player)
		return true;
	else if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] == player)
		return true;
	else if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] == player)
		return true;
	else if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] == player)
		return true;
	else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
		return true;
	else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == player)
		return true;

	return false;
}

/************************************************
* Function: printBoard
* Return: void
* Arguments: 3x3 TicTacToe board
* Description: Print the board in a human-
*  readable format
************************************************/
void printBoard(char board[3][3])
{
	cout << "\nCurrent gameboard:\n";
	cout << "       |       |\n";
	cout << " [1,1] | [1,2] | [1,3]\n";
	cout << "   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "\n";
	cout << "-------+-------+-------\n";
	cout << "       |       |\n";
	cout << " [2,1] | [2,2] | [2,3]\n";
	cout << "   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "\n";
	cout << "-------+-------+-------\n";
	cout << "       |       |\n";
	cout << " [3,1] | [3,2] | [3,3]\n";
	cout << "   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "\n";

	return;
}
