//Leetcode Problems/fourSum.cpp

/* Problem Statement: 
  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

  Note:
  Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
  The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

/* Solution: A classical type of problem, e.g., 2sum, 2sumclosest, 3Sum, 3SumClosest, 4Sum,..KSum problem 
  Step 1: Sorting the original array in a non-decreasing order, time complexity n*logn
  Step 2: for 2sum and 3sum, we can use the method of 2-pointers, which yields the time complexity n, n^2, respectively.
          for 4sum and more, we can recursively call its n-1 sum, until it is 2sum problem. 
          2sum problem can be implemented based on Hashmap, which has time complexity o(1), space complexity o(n).
          
  The following code has time complexity o(n^2), space complexisty o(n).        
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int B) {
    
        unordered_map<int, vector<pair<int, int> > > twoSumHash;
        vector<vector<int> > result;
        if(A.size() < 4)
            return result;
        // sort the input vector
        std::sort(A.begin(), A.end());
        // fill the hash map
        for(int i=0; i<A.size()-1; i++)
            for(int j=i+1; j<A.size(); j++)
                twoSumHash[A[i]+A[j]].push_back(std::make_pair(i, j));
    
        // start to search
        // the first adder
        for(int i=0; i<A.size()-3; i++) {
            // avoid repetition
            if(i>0 && A[i-1] == A[i])
                continue;
            for(int j=i+1; j<A.size()-2; j++) {
                // avoid repetion
                if(j>i+1 && A[j-1] == A[j])
                    continue;
                int candSum = B - (A[i] + A[j]);
                if(twoSumHash.find(candSum) != twoSumHash.end()) {
                    vector<pair<int, int>> candVec = twoSumHash[candSum];
                    // check every element of the vector if it should be included
                    for(int k=0; k<candVec.size(); k++) {
                        if(candVec[k].first <= j)
                            continue;
                        if(result.size() == 0)
                            result.push_back(vector<int>{A[i], A[j], A[candVec[k].first], A[candVec[k].second]});
                        else {
                            vector<int> lastQuad = result.back();
                            if(A[i] != lastQuad[0] || A[j] != lastQuad[1] || A[candVec[k].first] != lastQuad[2] || A[candVec[k].second] != lastQuad[3])
                                result.push_back(vector<int>{A[i], A[j], A[candVec[k].first], A[candVec[k].second]});
                        }
                    }
                }
                
            }
        }
        return result;
    }
};
