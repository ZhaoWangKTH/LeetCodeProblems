//Leetcode problem/postOrderTraversal.cpp

/* Problem statement: Post-oder traversal a BST without using recursion. */

/* Solution: 
    Trick 1: using stack<TreeNode*> 
    Trick 2: one extra variable, i.e., TreeNode* visited, to maitain the last visited tree node */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    if(A == NULL)
        return result;
    stack<TreeNode*> stk;
    
    TreeNode *current = A;
    TreeNode *lastVisited = NULL;
    
    while(!stk.empty() || current != NULL) {
        while(current!=NULL) {
            stk.push(current);
            current = current->left;
        }

        if(!stk.empty()) {
            current = stk.top();
            if(current->right == NULL || current->right == lastVisited) { 
                result.push_back(current->val);
                stk.pop();
                lastVisited = current;
                current = NULL;
            }
            else if(current->right != NULL && current->right != lastVisited) {
                current = current->right;
            }
        }
    }
    
    return result;
    
}
