// Leetcode Problem/isPowerThree.cpp

/* Problem Statement: Check if the input number is the power of three.*/

/* Solution: Recursion.*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        else if(n == 1)
            return true;
            
        int nDivThree = n/3;
        int residue = n%3;
        if(residue == 0) {
            if(isPowerOfThree(nDivThree))
                return true;
        }
        
        return false;
    }
};
