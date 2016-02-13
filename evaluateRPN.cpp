// Leetcode Problems/evaluateRPN.cpp

/* Problem statement:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

bool isOpe(string A)
{
    if(A=="+" || A=="-" || A=="*" || A=="/")
        return true;
    else
        return false;
}

int caculate(int x, int y, string A)
{
    if(A=="+")
        return x+y;
    else if(A=="-")
        return x-y;
    else if(A=="*")
        return x*y;
    else
        return x/y;
}

int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<int> stk;
    int result = 0;
    
    for(int i=0; i<A.size(); i++)
    {
        if(isOpe(A[i]))
        {
            int y = stk.top();
            stk.pop();
            int x = stk.top();
            stk.pop();
            result = caculate(x,y,A[i]);
            stk.push(result);
        }
        else
            stk.push(stoi(A[i], nullptr, 10));
    }
    
    return stk.top();
}
