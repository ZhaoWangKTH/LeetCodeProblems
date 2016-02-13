// Leetcode Problem /histogram.cpp

/* Problem Statement: See Largest Rectangular in a Histogram @Leetcode OJ
  Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

  Example Histogram

  Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

  Example2

  The largest rectangle is shown in the shaded area, which has area = 10 unit.

  For example,
  Given height = [2,1,5,6,2,3],
  return 10.  
*/

/* Solution: the most important thinking of the solution is to maintain an increasing stack: A[i1] < A[i2] < A[i3] ..., with i1, i2, i3... saved in the stack. Whenever come across a new entry A[i], pop the stack until the increasing order satisfies. 
  It is a similar problem as trapWater.cpp and slidingMaxWindow.cpp
  The detailed interatation can be found at http://www.geeksforgeeks.org/largest-rectangle-under-histogram/ 
*/

/* Here starts the code */ 

int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0)
        return 0;
    stack<int> myStk;
    myStk.push(0);
    
    int result = INT_MIN;
    
    // maintaining an increasing stack
    for(int i=1; i<A.size(); i++)
    {
        while(!myStk.empty() && A[myStk.top()]>=A[i])
        {
            int j = myStk.top();
            myStk.pop();
            int curArea = myStk.empty() ? A[j]*i : A[j]*(i-1-myStk.top());
            result = std::max(result, curArea);
        }
        myStk.push(i);
    }
    
    while(!myStk.empty())
    {
        int j = myStk.top();
        myStk.pop();
        int curArea = myStk.empty() ? A[j]*A.size() : A[j]*(A.size()-1-myStk.top());
        result = std::max(result, curArea);
    }
    
    return result;
}


