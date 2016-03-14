//Interviewbit.com/distinctNumWindow.cpp

/* Problem statement: You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:
- If K > N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].*/

/* Solution: use unordered_map<int, int>. For the current window, build the hashtable. Then for the next sliding window, it is easy to update the current hashtable by editing the element has been slided out and the element which is new. */

vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int, int> windowHash;
    vector<int> result;
    
    if(A.size() < B)
        return result;
    
    // the first window
    for(int i=0; i<B; i++)
        windowHash[A[i]]++;
    result.push_back(windowHash.size());
    
    // the siding window
    for(int i=1; i+B-1 <= A.size()-1; i++) {
        // A[i-1] has been out
        windowHash[A[i-1]]--;
        if(windowHash[A[i-1]] == 0)
            windowHash.erase(A[i-1]);
        windowHash[A[i+B-1]]++;
        result.push_back(windowHash.size());
    }
    
    return result;
}

