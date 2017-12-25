#pragma once
/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.
You may assume the following rules:
A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, 
vertical, or diagonal row wins the game.
*/
class TicTacToe {
private:
	vector<int> rows;
	vector<int> cols;
	int diags;
	int antiDiags;
	int N;
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		N = n;
		rows = vector<int>(n, 0);
		cols = vector<int>(n, 0);
		diags = 0;
		antiDiags = 0;
	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		int val = 0;
		if (player == 1) val = 1;
		else val = -1;
		rows[row] += val;
		cols[col] += val;
		if (row == col) diags += val;
		if (row + col == N - 1) antiDiags += val;
		if (abs(rows[row]) == N || abs(cols[col]) == N || abs(diags) == N || abs(antiDiags) == N) return player;
		else return 0;
	}
};

/**
* Your TicTacToe object will be instantiated and called as such:
* TicTacToe obj = new TicTacToe(n);
* int param_1 = obj.move(row,col,player);
*/