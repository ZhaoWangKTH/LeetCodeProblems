// Leetcode Problem/minWindowStr.cpp

/* Problem Statement: Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

/* Solution: The method of two pointers. Specifically, move the window end starting from the left until a window is valid. Then try to move the window head closer to the window end, such that a minimum window is found. Maintain this operation for the whole string, and output the minimum window. 
  E.g.: 
  s = ACBBACA
  t = ABA
  
  Preprocessor: using hash map to save all the freqency of characters in t. 
  
  Step 1: found window ACBBA to be valid, winstart = 0, winend = 4,
  Step 2: move winstart ahead, if the window is then not valid, move winend to the right. The window will look like this during the steps
      CBBA, not valid
      CBBAC, not valid
      CBBACA, valid again, move the winstart to be closer
      BBACA, valid
      BACA, valid and it is the minimum window! Output it!
*/

class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        
        if(s.size() < t.size())
            return result;
            
        // put t's char into hashmap
        unordered_map<char, int> exFreqChar;
        for(int i=0; i<t.size(); i++)
            exFreqChar[t[i]]++;
        // start to count the string s
        unordered_map<char, int> appearFreq;
        int winStart = 0;
        int winLen = INT_MAX;
        int matched = 0;
        
        int candStart = -1;
        int candEnd = -1;
        
        for(int winEnd = 0; winEnd < s.size(); winEnd++) {
            if(exFreqChar.find(s[winEnd]) != exFreqChar.end()) {
                appearFreq[s[winEnd]]++;
                if(appearFreq[s[winEnd]] <= exFreqChar[s[winEnd]])
                    matched++;
            }
            
            while(matched == t.size()) {
                // calculate the current window
                int curLen = winEnd-winStart+1;
                if(curLen < winLen)
                {
                    // update
                    winLen = curLen;
                    candStart = winStart;
                    candEnd = winEnd;
                }
                if(exFreqChar.find(s[winStart]) == exFreqChar.end() || appearFreq[s[winStart]] > exFreqChar[s[winStart]]) {
                    if(exFreqChar.find(s[winStart]) != exFreqChar.end())
                        appearFreq[s[winStart]]--;
                    winStart++;
                }
                else {
                    appearFreq[s[winStart]]--;
                    matched--;
                    winStart++;
                }
            }
        }
        
        if(candStart == -1)
            return "";
        else
            return s.substr(candStart, candEnd-candStart+1);
        
    }
};
