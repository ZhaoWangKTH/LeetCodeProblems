// LeetCode Problem/slidingMaxWindow.cpp

/* Problem Statement: 
  A long array A[] is given to you. There is a sliding window of size w which is moving from the very left of the array to the very right. You can only see the w numbers in the window. Each time the sliding window moves rightwards by one position.

Example :

The array is [1 3 -1 -3 5 3 6 7], and w is 3.

Window position	Max
 	 
[1 3 -1] -3 5 3 6 7	3
1 [3 -1 -3] 5 3 6 7	3
1 3 [-1 -3 5] 3 6 7	5
1 3 -1 [-3 5 3] 6 7	5
1 3 -1 -3 [5 3 6] 7	6
1 3 -1 -3 5 [3 6 7]	7
Input: A long array A[], and a window width w
Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
Requirement: Find a good optimal way to get B[i]

 Note: If w > length of the array, return 1 element with the max of the array. 
*/

/*  Solution -I: Using the abstract data structure "heap", which is priority_queue<> in C++ STL. The property of heap is that it is an ordered array, with the maximum value at the top. 
    As the heap is based on insertion, the construction of it offers a complexity O(N*logN).
    The following code has time complexity O(N*logN)...
*/


vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    
    if(B > A.size())
    {
        int maxi = INT_MIN;
        for(int i=0; i<A.size(); i++)
            maxi = std::max(maxi, A[i]);
        result.push_back(maxi);
        
        return result;
    }
    // using a priority-queue: a heap
    priority_queue<pair<int, int> > Q;
    for(int i=0; i<B; i++)
        Q.push(pair<int,int>(A[i],i));
    
    for(int i=B; i<A.size(); i++)
    {
        pair<int, int> p = Q.top();
        result.push_back(p.first);
        
        while(p.second <= i-B)
        {
            Q.pop();
            if(!Q.empty())
                p = Q.top();
            else
                break;
        }
        Q.push(pair<int,int>(A[i],i));
    }
    result.push_back(Q.top().first);
    
    return result;
}


/*  Solution-II: Using double queue, which is deque<> in the STL of C++.
    Maintaining a decreasing double queue: A[i1] > A[i2] > A[i3] > ... A[ix], with indices i1, i2, ..., ix saved in the queue. 
    Whenever come across a new entry A[i] as windown shifts, pop() the queue from the tail until the decreasing order is satisfied to append A[i]
    
    The current max in the window must be the first from the left (front) of the queue with index lies in the range of the current window.
    The following code offers the time complexity O(N).
*/

vector<int> Solution::slidingMaximumI(const vector<int> &A, int B) {
    vector<int> result;
    
    if(B > A.size())
    {
        int maxi = INT_MIN;
        for(int i=0; i<A.size(); i++)
            maxi = std::max(maxi, A[i]);
        result.push_back(maxi);
        
        return result;
    }
    
    // using the method of double queue
    // maintaining a decreasing queue, with the indices of elements saved in the queue
    deque<int> myQ;
    
    for(int i=0; i<B; i++)
    {
        while(!myQ.empty() && A[myQ.back()]<=A[i])
            myQ.pop_back();
        myQ.push_back(i);
    }
    result.push_back(A[myQ.front()]);
    
    for(int i=B; i<A.size(); i++)
    {
        // update the double queue, when come across the new element A[i]
        while(!myQ.empty() && A[myQ.back()]<=A[i])
            myQ.pop_back();
        myQ.push_back(i);
        // maintain the double queue from front, make sure the indices are in the current window
        while(!myQ.empty() && myQ.front()<=(i-B))
            myQ.pop_front();
            
        result.push_back(A[myQ.front()]);    
    }
    
    return result;
}
