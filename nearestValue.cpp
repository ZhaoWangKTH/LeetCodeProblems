// Leetcode problems/nearestValue.cpp

/* Problem Statement: 
  Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller     than i.

  More formally,

  G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
  Elements for which no smaller element exist, consider next smaller element as -1.

  Example:

  Input : A : [4, 5, 2, 10]
  Return : [-1, 4, -1, 2]

  Example 2:

  Input : A : [3, 2, 1]
  Return : [-1, -1, -1]
*/

/* Solution: Maintaining an increasing stack, with indices saved in the stack */

vector<int> Solution::prevSmaller(vector<int> &A) {
    // boundary check
    vector<int> result;
    if(A.size() == 0)
        return result;
    
    stack<int> myStk;
    //myStk.push(0);
    
    // maitaining an increasing stack
    for(int i=0; i<A.size(); i++)
    {
        while(!myStk.empty() && A[myStk.top()]>=A[i])
            myStk.pop();
        if(myStk.empty())
            result.push_back(-1);
        else
            result.push_back(A[myStk.top()]);
            
        myStk.push(i);    
    }
    
    return result;
}
