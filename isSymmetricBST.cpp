//Leetcode problem/isSymmetricBST.cpp

/* Problem Statement: Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). */

/* Solution: Flip its right tree. If it is the same as its left tree, return true; otherwise, return false. */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int isSameTree(TreeNode* A, TreeNode* B) {
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

void invertTree(TreeNode* A) {
    if(A == NULL)
        return;
        
    TreeNode* temp = A->left;
    A->left = A->right;
    A->right = temp;
    
    invertTree(A->left);
    invertTree(A->right);
}
 
int Solution::isSymmetric(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == NULL)
        return true;
        
    invertTree(A->right);
    
    if(isSameTree(A->left, A->right))
        return true;
    else
        return false;
}
