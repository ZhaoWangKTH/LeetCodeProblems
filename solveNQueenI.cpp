// Leetcode problems/solveNQueenI.cpp

// Very classical problem: Using back-tracking algorithm to solve it 
// There exists an awesome detailed interpretation of this problem at http://www.cnblogs.com/TenosDoIt/p/3801621.html 
// BT algorithm shares a lot in common with DFS 

class Solution {
    private: vector<vector<string> > result;
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curRes;
        for(int i=0; i<n; i++)
            curRes.push_back(string(n,'.'));
        solver(curRes, 0);
        return result;
    }
    
    void solver(vector<string> &cur, int row) {
        if(row == cur.size())
        {
            result.push_back(cur);
            return;
        }
        
        for(int col=0; col<cur.size(); col++)
        {
            if(isValidPos(cur, row, col))
            {
                cur[row][col] = 'Q';
                solver(cur, row+1);
                cur[row][col] = '.';
            }
        }
    }
    
    bool isValidPos(vector<string> &cur, int row, int col) {
        // check the col
        for(int i=0; i<row; i++)
            if(cur[i][col] == 'Q') return false;
            
        // check the left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
            if(cur[i][j] == 'Q') return false;
            
        // check the right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<cur.size(); i--, j++)
            if(cur[i][j] == 'Q') return false;
        
        return true;    
    }
};
