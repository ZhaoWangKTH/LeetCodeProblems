// Leetcode Problem/isPowerOfTwo.cpp

/* Bit operation: whenever n is a power of 2, it is equivalent that n>0 and n & n-1 = 0.*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        else {
            if((n & (n-1)) == 0)
                return true;
            else
                return false;
        }
    }
};
