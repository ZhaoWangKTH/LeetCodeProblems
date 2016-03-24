//Leetcode problems/sortedArrayToBST.cpp

/*Problem statement: Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3
 */

/* Solution: Recursion and Bisection method  */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* convert(TreeNode* root, const vector<int> &A, int start, int end) {
    int len = end - start + 1;
    
    if(len <= 0)
        return root;
    
    int mid = start + (end-start)/2;
    root = new TreeNode(A[mid]);
    
    root->left = convert(root->left, A, start, mid-1);
    root->right = convert(root->right, A, mid+1, end);
    
    return root;
}
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* root = NULL;
    if(A.size()==0)
        return root;
    
    root = convert(root, A, 0, A.size()-1);
    
    return root;
}
