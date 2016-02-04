// Leetcode Problem/isValidParenthesis.cpp

/* Problem Statement
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

  Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

/* Note: A classic toy example of using stack for char matching */


bool isCharMatch(char A, char B) {
    if(A == '}' || A == ')' || A == ']')
        return false;
    else
    {
        string temp;
        temp.push_back(A);
        temp.push_back(B);
        if(temp == "()" || temp == "[]" || temp == "{}")
            return true;
        else
            return false;
    }
}

int Solution::isValid(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<char> stk;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == '{' || A[i] == '(' || A[i] == '[')
            stk.push(A[i]);
        else
        {
            if(stk.empty())
                return 0;
            else
            {
                if(isCharMatch(stk.top(), A[i]))
                    stk.pop();
                else
                    return 0;
            }
        }
    }
    if(stk.empty())
        return 1;
    else
        return 0;
}

