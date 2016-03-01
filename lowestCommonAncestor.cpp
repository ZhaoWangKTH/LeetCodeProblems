// Leetcode Problem/lowestCommonAncestor.cpp

/* Problem Statement: Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

*/

/* Solution: 
  1) make sure if both of the nodes exist in the tree (visit all nodes)
  2) if the first step is true, divide and conquer (function: TreeNode* lcaNode(TreeNode* root, int val1, int val2) )
  Note: I am not sure if better solution exists... likely there will be a better one. 
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

bool isValid(TreeNode* root, int value) {
    if(root == NULL)
        return false;
    
    if(root->val == value || isValid(root->left, value) || isValid(root->right, value))
        return true;
    else
        return false;
} 
 
TreeNode* lcaNode(TreeNode* root, int val1, int val2) {
    if(root == NULL || root->val == val1 || root->val == val2) {
         return root;
    }
     
    TreeNode* left = lcaNode(root->left, val1, val2);
    TreeNode* right = lcaNode(root->right, val1, val2);
     
    if(left!=NULL && right!=NULL)
        return root;
    if(left != NULL)
        return left;
    if(right != NULL)
        return right;
    
    return NULL;
 }
 
int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(isValid(A, val1) && isValid(A, val2)) {
        TreeNode *lca = lcaNode(A, val1, val2);
        if(lca == NULL)
            return -1;
        else
            return lca->val;
    }
    else
        return -1;
}
