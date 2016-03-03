//Leetcode Problems/pathSumBT.cpp

/* Problem Statement: Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/

/* Solution: Recusion. Similar to the problem: Sum Root to Leaf Numbers. */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void allPathSum(TreeNode* root, int curSum, vector<int>& pathSum) {
    if(root == NULL)
        return;
    
    curSum = curSum + root->val;
    if(root->left==NULL && root->right==NULL) 
        pathSum.push_back(curSum);
        
    if(root->left) allPathSum(root->left, curSum, pathSum);
    if(root->right) allPathSum(root->right, curSum, pathSum);
}
 
int Solution::hasPathSum(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> pathSum;
    
    allPathSum(A, 0, pathSum);
    
    for(int i=0; i<pathSum.size(); i++) {
        if(pathSum[i] == B) 
            return true;
    }
    return false;
}
