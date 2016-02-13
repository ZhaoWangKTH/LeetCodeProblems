// Leetcode Problem/minStack.cpp

/* Problem Statement
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

/* Using two stacks, one to save all the element, and the other one is to maintain a non-increasing sequence */

class MinStack{
    private:
        stack<int> myStk;
        stack<int> minStk;
    public:
        MinStack(); // default constructor
        void push(int);
        void pop();
        int top();
        int getMin();
}

MinStack::MinStack() {
    while(!myStk.empty())
        myStk.pop();
    while(!minStk.empty())    
        minStk.pop();
}

void MinStack::push(int x) {
    myStk.push(x);
    if(minStk.empty() || minStk.top()>= x)
        minStk.push(x);
}

void MinStack::pop() {
    if(myStk.empty())
        return;
    if(!minStk.empty() && myStk.top() == minStk.top())
        minStk.pop();
        
    myStk.pop();    
}

int MinStack::top() {
    if(myStk.empty())
        return -1;
    else
        return myStk.top();
}

int MinStack::getMin() {
    if(minStk.empty())
        return -1;
    else
        return minStk.top();
}
