//LeetCode Problems/minDepthBTree.cpp

/* Problem Statement: Find the minimum depth of all paths in a binary tree 
  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

  NOTE : The path has to end on a leaf node. 
  Example :

         1
        /
       2
  min depth = 2.

*/

/* Solution: Recursion. Pay attention to the case that a node has one leaf, with the other leaf to be NULL. In this case, the min path passes through the valid leaf. 
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
int Solution::minDepth(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(root == NULL)
        return 0;
        
    if(root->left!=NULL && root->right==NULL)
        return 1+minDepth(root->left);
        
    if(root->right!=NULL && root->left==NULL)
        return 1+minDepth(root->right);
            
    return 1+std::min(minDepth(root->left), minDepth(root->right));    
}
