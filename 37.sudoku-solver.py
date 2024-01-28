#
# @lc app=leetcode id=37 lang=python3
#
# [37] Sudoku Solver
#

# @lc code=start
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        self.solve(board)
    

    def solve(self, board):
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == '.':
                    for c in range(1, 10):
                        if self.is_valid(board, i, j, str(c)):
                            board[i][j] = str(c)

                            if self.solve(board):
                                return True
                            else:
                                board[i][j] = '.'
                        
                    return False

        return True
    

    def is_valid(self, board, row, col, target):
        blk_row = (row // 3) * 3
        blk_col = (col // 3) * 3
        for i in range(len(board)):
            if board[row][i] == str(target) or board[i][col] == str(target) or board[blk_row + i // 3][blk_col + i % 3] == str(target):
                return False
        return True
        
# @lc code=end

