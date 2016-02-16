// Leetcode Problems/sudokuSolver.cpp

/* Problem statement: solve the sudoku given in the vector<vector<char>> board */
/* Solution: Back-Tracking algorithm, similar to the problem of NQueen */

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size()<9 || board[0].size()<9)
            return;
        solver(board, 0, 0);
        return;
    }
    
    bool solver(vector<vector<char>> & board, int row, int col) {
        if(row >= 9)
            return true;
        
        if(board[row][col] == '.')
        {
            for(int cand = 1; cand <=9; cand++)
            {
                if(isValid(board, row, col, cand))
                {
                    board[row][col] = cand + '0';
                    // check where to go
                    if(col == 8)
                    {   
                        if(solver(board, row+1, 0)) return true;
                    }
                    else
                    {
                        if(solver(board, row, col+1)) return true;
                    }
                    // set back
                    board[row][col] = '.';
                }
            }
        }
        else // board[row][col] is already a number
        {
            // check where to go
            if(col == 8)
            {
                if(solver(board, row+1, 0)) return true;
            }
            else
            {   
                if(solver(board, row, col+1))   return true;
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>> & board, int row, int col, int candi) {
        // check the row
        for(int j=0; j<9; j++)
            if(board[row][j] == candi + '0' && j!=col) return false;
            
        // check the col
        for(int i=0; i<9; i++)
            if(board[i][col] == candi + '0' && i!=row) return false;
            
        // check its square
        int squRow = row/3*3;
        int squCol = col/3*3;
        
        for(int i=squRow; i<squRow+3; i++)
            for(int j=squCol; j<squCol+3; j++)
                if(board[i][j] == candi+'0' && (i!=row || j!=col))
                    return false;
                    
        return true;            
    }
};
