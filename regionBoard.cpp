// Interviewbit.com/regionBoard.cpp

/* Problem Statement: Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

/* Solution: DFS or BFS. For any 'O' in the boundary, mark its neigbors who are 'O' to 'M'. In the end, the left 'O's are the wanted regions. Therefore, we can flip them to 'X', and set 'M' to originals. */

void markBoundary(int i, int j, vector<vector<char> >& A) {
    A[i][j] = 'M';
    
    if(i>0 && A[i-1][j] == 'O')
        markBoundary(i-1, j, A);
    if(i<A.size()-1 && A[i+1][j] == 'O')
        markBoundary(i+1, j, A);
    if(j>0 && A[i][j-1] == 'O')
        markBoundary(i, j-1, A);
    if(j<A[0].size()-1 && A[i][j+1] == 'O')
        markBoundary(i, j+1, A);
}


void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int M = A.size();
    int N = A[0].size();
    
    // upper and lower boundary
    for(int j=0; j<N; j++) {
        if(A[0][j] == 'O')
            markBoundary(0, j, A);
        
        if(A[M-1][j] == 'O')
            markBoundary(M-1, j, A);
    }
    
    // left and right boundary
    for(int i=1; i<M-1; i++) {
        if(A[i][0] == 'O')
            markBoundary(i, 0, A);
        
        if(A[i][N-1] == 'O') 
            markBoundary(i, N-1, A);
    }
        
    
    // visit
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(A[i][j] == 'O' ) {
                A[i][j] = 'X';
            }
            else if(A[i][j] == 'M')
                A[i][j] = 'O';
        }
    }
}
