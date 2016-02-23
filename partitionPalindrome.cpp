// Leetcode/partitionPalin.cpp

/* 
  Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
*/

/* Solution: Classical Backtracking */



bool isParlin(string A) {
    if(A.size() == 1)
        return true;
        
    int low = 0;
    int hi = A.size()-1;
    
    while(low < hi)
    {
        if(A[hi] != A[low])
            return false;
        else {
            hi--;
            low++;
        }
    }
    
    return true;
}

void setPartition(vector<vector<string> > &result, vector<string> &curStrVec, string A, int low) {
    if(low == A.size())
    {
        result.push_back(curStrVec);
        return;
    }
    
    for(int high = low+1; high <= A.size(); high++) {
        
        string curStr(A.begin()+low, A.begin()+high);
        
        if(isParlin(curStr)) {
            // save the current vector information
            //int curSize = curStrVec.size();
            // put the current string to the current vector
            curStrVec.push_back(curStr);
            // check from the next position
            setPartition(result, curStrVec, A, high);
            // set back
            //curStrVec.resize(curSize);
            curStrVec.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string> > result;
    vector<string> curStrVec;
    
    setPartition(result, curStrVec, A, 0);
    
    return result;
}
