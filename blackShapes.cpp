//interviewbit.com/blackShapes.cpp

/* Problem Statement: Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
(iii)
      X
      X
Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.

/* Solution: Graph traversal. Maintaining an adjacency matrix to save visited status. */
/* Note: One of the standard way of passing the pointer of 2D array to function (I have made some mistake here initially):
    type** 2dArray;
    2dArray = new type* [M];
    for(i=1:M)
      2dArray[i] = new type [N];
    
    ...
    
    void function(type **);
    
    call:
    function(2dArray) is OK!
*/
bool traversal(vector<string> &A, bool** visitedMat, int i, int j) {
    int M = A.size();
    int N = A[0].size();
    
    if(i>=M || j>=N) 
        return false;
        
    visitedMat[i][j] = true;
    // up
    if(i>0 && A[i-1][j] == 'X' && visitedMat[i-1][j] == false)
        traversal(A, visitedMat, i-1, j);
    // lower
    if(i<M-1 && A[i+1][j] == 'X' && visitedMat[i+1][j] == false)
        traversal(A, visitedMat, i+1, j);
    // left
    if(j>0 && A[i][j-1] == 'X' && visitedMat[i][j-1] == false)
        traversal(A, visitedMat, i, j-1);
    // right
    if(j<N-1 && A[i][j+1] == 'X' && visitedMat[i][j+1] == false)
        traversal(A, visitedMat, i, j+1);

        
    return true;
}

int Solution::black(vector<string> &A) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 0)
        return 0;
        
    int M = A.size();
    int N = A[0].size();
    
    bool** visitedMat;
    visitedMat = new bool *[M];
    
    for(int i=0; i<M; i++)
        visitedMat[i] = new bool [N];
    
    for(int i=0; i<M; i++) 
        for(int j=0; j<N; j++) 
            visitedMat[i][j] = false;
    
    int result = 0;
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(A[i][j] == 'X' && visitedMat[i][j] == false) {
                result++;
                // traversal from this point
                traversal(A, visitedMat, i,j);
            }
        }
    }
    
    return result;
}
