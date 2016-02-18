// Leetcode Problem/inorderTraversal.cpp

/* left->root->right without recursion */
/* Using stack to help traversal */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    
    if(A == NULL)
        return result;
    
    stack<TreeNode*> rootStk;
    TreeNode *cur = A;
    
    while(cur!=NULL || !rootStk.empty()) {
        if(cur != NULL)
        {
            rootStk.push(cur);
            cur = cur->left;
        }
        else if(!rootStk.empty())
        {
            cur = rootStk.top();
            rootStk.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    
    return result;
}
