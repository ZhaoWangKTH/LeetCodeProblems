// Leetcode problem/nextPermutation.cpp

/* Problem Statement: find the next permutation of input array */
/* Solution: try to find the pattern of permutations */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return;
        
        // find the first non-increasing index from right to left
        int vioId = -1;
        for(int i=n-1; i>=1; i--) {
            if(nums[i-1] < nums[i])
            {
                vioId = i-1;
                break;
            }
        }
        
        int changeId = -1;
        if(vioId >= 0) {
            // find the first ele that is greater than nums[vioId]
            for(int i=n-1; i>vioId; i--) {
                if(nums[i] > nums[vioId])
                {
                    changeId = i;
                    break;
                }
            }
            
            if(changeId >= 0) {
                int temp = nums[vioId];
                nums[vioId] = nums[changeId];
                nums[changeId] = temp;
            }
        }
        
         // reverse from the right to left, from n-1 to vioId+1
        int low = vioId + 1;
        int hi = n-1;
        for(;low < hi; low++, hi--) {
            int temp = nums[hi];
            nums[hi] = nums[low];
            nums[low] = temp;
        }
    }
};
