// Leetcode/twoSumHash.cpp

/* Problem Statement: Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
*/

/* Solution: If the array is sorted, the two-pointer method can be applied. However, it is not the case here. 
    Use unordered_map<> as hashmap instead. 
    Traversal the array numbers from i=0:end-1.
    Treat the element: <num, index> in the hashmap as candidates of the first adder, and the current value: numbers[i] as the second order:
    if found the first adder = target - number[i] in the hashmap, we found the pair! End!
    else insert the current pair<number[i], i+1> to the hashmap.  
    
   The trick is that when we traversal the array from 0 to end-1, the potential index for the second adder is increasing. Therefore, the order is guranteed.   
*/

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    map<int, int> hash;
    
    for(int i=0; i<numbers.size(); i++) {
        // treat number[i] as the second adder
        int adder1 = target - numbers[i];
        if(hash.find(adder1) != hash.end()) {
            // found adder1
            result.push_back(hash[adder1]);
            result.push_back(i+1);
            break;
        }
        else // did not find it
        {
            // push the current <key, index> into hash, such that hash[key] = index+1 (increasing w.r.t. i)
            if(hash[numbers[i]] == 0)
                hash[numbers[i]] = i+1;
            // otherwise, hash[numbers[i]] has already been occupied: skip this step
        }
    }
    return result;
}
