//Leetcode problems/kthSmallestBST.cpp

/* Problem statement: Given a binary search tree, write a function to find the kth smallest element in the tree.

NOTE : You may assume 1 <= k <= Total number of nodes in BST */

/* Solution Inorder traversal and return the kth in the result.*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorderTraversal(TreeNode *root, vector<int> & result) {
    if(root == NULL)
        return;
        
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
    
    return;
} 
 
int Solution::kthsmallest(TreeNode* root, int k) {
    vector<int> sorted;
    inorderTraversal(root, sorted);
    
    return sorted[k-1];
}
