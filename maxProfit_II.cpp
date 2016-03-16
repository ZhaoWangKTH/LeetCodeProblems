//Leetcode problems/maxProfit_II.cpp

/* Problem statement: Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input : [1 2 3]
Return : 2 

*/

/* Solution: transform the orginal vector into a difference vector A[i] - A[i-1] for every i=1:N. Sum all the positive items. */

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 0)
        return 0;
    int result = 0;    
    for(int i=1; i<A.size(); i++) {
        int diff = A[i] - A[i-1];
        if(diff > 0)
            result += diff;
    }
    
    return result;
}
