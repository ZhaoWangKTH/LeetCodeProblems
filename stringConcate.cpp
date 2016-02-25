// Leetcode Problem/stringConcate.cpp

/* Problem Statement: You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).
*/

/* Solution: Hash the list, save frequency of all words. Compare it with each window which has length = totalwordlength.
   Not a hard problem. 
*/


bool isValidConcate(string &s, unordered_map<string, int> &expectHash, int wordLen) {
    unordered_map<string, int> appearHash;
    for(int i=0; i<=s.size() - wordLen; i=i+wordLen) {
        string curWord = s.substr(i, wordLen);
        if(expectHash.find(curWord) == expectHash.end()) 
            return false;
        else {
            appearHash[curWord]++;
            if(appearHash[curWord] > expectHash[curWord])
                return false;
        }
    }
    return true;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    if(B.empty())
        return result;
    int wordLen = B[0].size();    
        
    unordered_map<string, int> expectHash;
    int expectLen = 0;
    for(int i=0; i<B.size(); i++) {
        expectHash[B[i]]++;
        expectLen += B[i].size();
    }
    if(A.size() < expectLen)
        return result; 
    
    for(int winStart = 0; winStart <= A.size()-expectLen; winStart++) {
        string curStr = A.substr(winStart, expectLen);
        if(isValidConcate(curStr, expectHash, wordLen)) 
            result.push_back(winStart);
        else
            continue;
    }
    
    return result;
}
