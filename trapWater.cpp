//LeetCode Problem/trapWater.cpp

/* Problem Statement

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

/*
  Solution-A: Brute-force
  for every index i, find the leftmax value to its left and rightmax value to its right, caculate its capacity: min(leftmax, rightmax) - height[i]
  sum over all. 
  
  Solution-B: Keep a monotone decreasing height sequence, with the corresponding indices saved in the stack.
  Whenever come across a new height[i], which violates the strickly decreasing rule, caculate the current capability for trapping water. And then pop() the top value in the stack. Keep doing this caculation and popping until the new height[i] satisfies the decreasing order, such than index i can be pushed to the stack. 
  
  In what follows, it is the code for solution-B. 
*/

int Solution::trap(vector<int>& height) {
    auto n = height.size();
    if(n < 3)
        return 0;
    
    int result = 0;
    stack<int> stk;
    stk.push(0);
    
    for(int i=0; i<n; i++){
        int j = stk.top();
        if(height[i] == height[j])
            stk.pop();
        else if(height[i] > height[j])
        {
            while(!stk.empty())
            {
                int bottom = height[stk.top()];
                stk.pop();
                if(stk.empty())
                    break;
                else
                {
                    j = stk.top();
                    int temp = (std::min(height[i],height[j]) - bottom) * (i-j-1);
                    result += temp;
                    if(height[i] < height[j])
                        break;
                    else {}
                }
            }
        }
        else {} // height[i] < height[j], do nothing
        
        stk.push(i);
    }
    
    return result;
}
