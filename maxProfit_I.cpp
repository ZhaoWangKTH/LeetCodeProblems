// Leetcode problems/maxProfit_I.cpp

/* Problem statement: Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example :

Input : [1 2]
Return :  1 

*/

/* Solution: Dynamic programming. */


int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 0)
        return 0;
    int result = INT_MIN;
    int curMin = A[0];
    
    for(int i=0; i<A.size(); i++) {
        result = std::max(A[i] - curMin, result);
        curMin = std::min(curMin, A[i]);
    }
    
    return result;
}
