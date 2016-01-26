// interviewbit.com/StackAndQueues/simplifyPath.cpp

/*
  Given an absolute path for a file (Unix-style), simplify it.
  Examples:

  path = "/home/", => "/home"
  path = "/a/./b/../../c/", => "/c"
  Note that absolute path always begin with ‘/’ ( root directory )
  Path will not have whitespace characters.
*/

/*
  seperate each substring between '/' and '/'
  case1: ".." pop the top element of the stack
  case2: "." go ahead to the next substring
  case3: "///" go ahead
  case4: Otherwise, push_back to the stack<string> 
*/

string Solution::simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 0)
        return NULL;
    
    assert(A[0] == '/');
    vector<string> stk;
    int i=0;
    while(i<A.size())
    {
        while(A[i] == '/')
            i++;
        if(i==A.size())
            break;
            
        int start = i;
        while(A[i] != '/' && i<A.size())
            i++;
        string curStr = A.substr(start, i-start);    
        if(curStr == "..")
        {
            if(!stk.empty())
                stk.pop_back();
        }
        else if(curStr != ".")
            stk.push_back(curStr);
    }
    
    if(stk.empty())
        return "/";
    string simPath("");
    for(int i=0; i<stk.size();i++)
        simPath += "/" + stk[i];
    return simPath;
}
