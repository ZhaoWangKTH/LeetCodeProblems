// Leetcode Problems/preorderTraversal.cpp

/*  root->left->right traversal without recursion 
    This is a similar problem of inorderTraversal problem. A stack is used to help recusion. 
    The stopping criteria is the (Stack is empty) && (the current node is NULL)
    If current node is not null: access, and cur = cur->left, meanwhile put its right-leaf into stack
    It the current node is null but stack has elements, cur = stack.top(), pop it from the stack. Meanwhile access it, and repeat the last step. 
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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    if(A == NULL)
        return result;
    
    TreeNode* cur = A;
    stack<TreeNode*> nodeStk;
    
    while(cur!=NULL || !nodeStk.empty()) {
        if(cur!=NULL)
        {
            // access cur->val
            result.push_back(cur->val);
            // save its right
            if(cur->right!=NULL)
                nodeStk.push(cur->right);
            // go left    
            cur = cur->left;
        }
        else if(!nodeStk.empty()) {
            cur = nodeStk.top();
            nodeStk.pop();
            // access cur->val
            result.push_back(cur->val);
            // save its right leaf
            if(cur->right!=NULL)
                nodeStk.push(cur->right);
            // go left    
            cur = cur->left;
        }
    }
    
    return result;
}
