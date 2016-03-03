//Leetcode problem/identialBST.cpp

/* Problem Statement: Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

/* Solution: Recursion. Pay attention to the corner cases. */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == NULL && B == NULL)
        return true;
    else if(A == NULL && B != NULL)
        return false;
    else if(A != NULL && B == NULL)
        return false;
        
    if(A->val != B->val)
        return false;
        
    if(A->val == B->val && isSameTree(A->left, B->left) && isSameTree(A->right, B->right))
        return true;
    else
        return false;
}
