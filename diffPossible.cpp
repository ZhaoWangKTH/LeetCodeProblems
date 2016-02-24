// Leetcode Problem/diffPossible.cpp

/* Problem Statement: Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that     A[i] - A[j] = k, i != j.

  Example :

  Input :

  A : [1 5 3]
  k : 2
  Output : 1
  as 3 - 1 = 2

  Return 0 / 1 for this problem.
*/


/* Solution: 
  Step1: for j=0:n-1, A[i] - A[j] = target, for each A[j] insert (target+A[j], j) to the hashmap. 
  Step2: for each A[j], search if target+A[j] in the hashmap, if exists: check if the index is the same, if different: found!
*/


int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 2)
        return false;
    
    unordered_map<int, int> diffHash;
    for(int i=0; i<A.size(); i++) {
        diffHash[A[i]] = i;
    }

    for(int j=0; j<A.size(); j++) {
        if(diffHash.find(B+A[j]) != diffHash.end()) {
                if(diffHash[B+A[j]] != j) // found
                    return true;
        }
    }
    
    return false;
}
