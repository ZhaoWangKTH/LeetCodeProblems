// Leetcode problem/isValidBST.cpp

/* Problem Statement:
  Check if a BST is valid:
  1) left < root < right for every root if not emtpy
  2) left is a valid BST
  3) right is a valid BST
*/

/* Solution: The most importent observation of this problem is that BST can divide the real line (-\infty, +\infty) to fine intervals.
  In the beginning, the interval is (-\infty, +\infty) which can be seen a interval (min = -\infty, max = +\infty)
  After the first node is inserted, say value = a, then its left tree should lies in the interval (min, a); meanwhile, its right tree should lies in the interval [a, max].
  Therefore, if we go from the current node to its left, the 'max'-boundary should be updated and the valid region becomes (min,max =a);
  similarly, if we go to its right, the 'min'-boundary should be updated and the valid domain becomes (min=a, max).
  
  Very interesting and classic program to help understand binary search tree. 
*/  
  
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isValidCheck(TreeNode* root, long min, long max) {
        if(root==NULL)
            return true;
        
        if(root->val >= max)
            return false;
        if(root->val <= min)
            return false;
            
        bool leftValid = isValidCheck(root->left, min, root->val);
        bool rightValid= isValidCheck(root->right, root->val, max);
        
        return (leftValid && rightValid);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return isValidCheck(root, LONG_MIN, LONG_MAX);    
    }        
};
