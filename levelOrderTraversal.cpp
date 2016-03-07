//Leetcode problem/levelOrderTraversal.cpp

/* Solution: BFS. Maintain the following variables: curLevExpected, curLevVisited, nextLevExpected, to represent the number of tree nodes of each level. */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // BFS traversal
    queue<TreeNode*> myQue;
    vector<vector<int>> result;
    
    if(A==NULL)
        return result;
        
    myQue.push(A);
    int curLevVisited = 0;
    int curLevExpected = 1;
    int nextLevExpected = 0;
    vector<int> curLevRes;
    
    while(!myQue.empty()) {
        // access the current node
        TreeNode *curNode = myQue.front();
        curLevVisited++;
        curLevRes.push_back(curNode->val);
        
        // queue its child
        if(curNode->left!=NULL) {
            myQue.push(curNode->left);
            nextLevExpected++;
        }
        
        if(curNode->right!=NULL) {
            myQue.push(curNode->right);
            nextLevExpected++;
        }
        
        if(curLevVisited == curLevExpected) {
            result.push_back(curLevRes);
            curLevRes.clear();
            curLevVisited = 0;
            curLevExpected = nextLevExpected;
            nextLevExpected = 0;
        }
        myQue.pop();
    }
    
    return result;
}
