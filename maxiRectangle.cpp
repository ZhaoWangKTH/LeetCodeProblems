// Leetcode problem/maxiRectangle.cpp

/* Problem statement: Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A :  1 1 1
     0 1 1
     1 0 0 

Output : 4 */

/* Solution: Similar to the maximal square in matrix problem at http://www.ideserve.co.in/learn/maximum-size-square-sub-matrix-with-all-1s, which is solved by dynamic programming, one solution here will be using an adjacency matrix A with the element A[i][j] to represent the maximul area of all the rectangle's whose bottom_right element is matrix[i][j]. This method has time complexity O(n^{3}). 

  A better solution is based on the method of "maximal rectangle in histgram (shown in histgram.cpp in this repository)". Specifically, for every row of the input matrix, we calculate its histgram. As then call the method in histgram.cpp to give the maximal area of rectangles which have their baseline as this row. For example:
  0 0 1 1    HISTGRAM:    0 0 1 1
  1 1 1 0                 1 1 2 0
  1 0 1 1                 2 0 3 1
  1 1 1 0                 3 1 4 0
  
  The output is 4. 
  
  A very good explanation of this algorithm can be found in http://www.cnblogs.com/lichen782/p/leetcode_maximal_rectangle.html 
  Thanks to the contributor: lichen782. 
  
*/


class Solution {
private: 
    vector<vector<int>> calculateHist(vector<vector<char>> & matrix) {
        vector<vector<int> > result;
        if(matrix.size() == 0)
            return result;
        
        // push back the histgram
        for(int i=0; i<matrix.size(); i++) {
            vector<int> curHist;
            for(int j=0; j<matrix[0].size(); j++) {
                if(i==0) {
                    if(matrix[i][j] == '0')
                        curHist.push_back(0);
                    else
                        curHist.push_back(1);
                }
                else { // not the first row
                    if(matrix[i][j] == '0')
                        curHist.push_back(0);
                    else
                        curHist.push_back(result[i-1][j] + 1);
                }
            }
            result.push_back(curHist);
        }
        return result;
    }
    
    int maxRectHist(vector<int> & histgram) {
        if(histgram.size() == 0)
            return 0;
            
        int N = histgram.size();    
        int result = 0;
        stack<int> stk;
        stk.push(0);
        
        for(int i=1; i<N; i++) {
            if(!stk.empty() && histgram[i] > histgram[stk.top()])
                stk.push(i);
            else {
                if(stk.empty())
                    stk.push(i);
                else {
                    while(!stk.empty() && histgram[i] <= histgram[stk.top()]) {
                        int j = stk.top();
                        stk.pop();
                        result = std::max(result, stk.empty() ? histgram[j]*i : histgram[j]*(i-1-stk.top()));
                    }
                    stk.push(i);
                }
            }
        }
        
        // until stk is empty
        while(!stk.empty()) {
            int j = stk.top();
            stk.pop();
            if(stk.empty())
                result = std::max(result, histgram[j]*N);
            else {
                int area = histgram[j] * (N - stk.top() - 1);
                result = std::max(result, area);
            }
        }
        
        return result;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        // get histgram of every row in the matrix    
        vector<vector<int> > histgram = calculateHist(matrix);
        int result = 0;
        for(int i=0; i<histgram.size(); i++) {
            int tempMax = maxRectHist(histgram[i]);
            result = std::max(tempMax, result);
        }
        return result;
    }
};
