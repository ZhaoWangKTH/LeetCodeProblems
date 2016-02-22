// Leetcode Problem/letterPhone.cpp

/* Problem Statement: Given a digit string, return all possible letter combinations that the number could represent.
  The digit 0 maps to 0 itself.
  The digit 1 maps to 1 itself.

  Input: Digit string "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
  Make sure the returned strings are lexicographically sorted.
*/

void settleCombination(vector<string> &result, string curStr, string A, int step) {
    if(step == A.size()) {
        result.push_back(curStr);
        return;
    }    
    // start to check the current char
    int curCase = -1;
    if(A[step] == '0') {
        curStr.push_back('0');
        settleCombination(result, curStr, A, step+1);
    }
    else if(A[step] == '1') {
        curStr.push_back('1');
        settleCombination(result, curStr, A, step+1);
    }
    else if(A[step] == '2' || A[step] == '3' || A[step] == '4' || A[step] == '5' || A[step] == '6') {
        string temp(curStr);
        curStr.push_back('a'+(A[step]-'2')*3);
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('b'+(A[step]-'2')*3);
        settleCombination(result, curStr, A, step+1);
            // set curStr back
        curStr = temp;
        curStr.push_back('c'+(A[step]-'2')*3);
        settleCombination(result, curStr, A, step+1);
    }
    else if(A[step] == '7') {
        string temp = curStr;
        curStr.push_back('p');
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('q');
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('r');
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('s');
        settleCombination(result, curStr, A, step+1);
    }
    else if(A[step] == '9') {
        string temp = curStr;
        curStr.push_back('w');
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('x');
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('y');
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('z');
        settleCombination(result, curStr, A, step+1);

        
    }
    else if(A[step] == '8') {
        string temp = curStr;
        curStr.push_back('t');
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('u');
        settleCombination(result, curStr, A, step+1);
        // set curStr back
        curStr = temp;
        curStr.push_back('v');
        settleCombination(result, curStr, A, step+1);
    }
    
}

vector<string> Solution::letterCombinations(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    
    vector<string> result;
    string curStr;
    
    settleCombination(result, curStr, A, 0);
    return result;
}
