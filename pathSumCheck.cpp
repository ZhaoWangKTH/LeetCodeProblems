//Leetcode problems/pathSumCheck.cpp 

/* Problem Statement: Root to Leaf Paths With SumBookmark
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/* Solution: Recursion + Traceing back. 
  Remember to pop every node after visiting, as typical tracing back. 
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void pathSumCheck(TreeNode* root, int alreadySum, int target, vector<int> &curPath, vector<vector<int>> &result) {
    if(root==NULL)
        return;
    
    // update already sum
    alreadySum += root->val;
    curPath.push_back(root->val);
    
    if(alreadySum == target && root->left==NULL && root->right==NULL) {
        result.push_back(curPath);
        curPath.pop_back();
        return;
    }
    
    if(root->left != NULL)
        pathSumCheck(root->left, alreadySum, target, curPath, result);
    if(root->right != NULL)
        pathSumCheck(root->right, alreadySum, target, curPath, result);
    
    curPath.pop_back();    
    return;    
} 
 
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> result;
    vector<int> curPath;
    
    pathSumCheck(root, 0, sum, curPath, result);
    return result;
}
