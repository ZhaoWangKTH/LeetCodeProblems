//Leetcode Problems/rootLeafSum.cpp

/* Problem statement: Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/* Solution: Recursion. 
    
   How to do it without recursion? Solution seeking...   
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
        void generateSum(TreeNode* root, int curNum, int& sum) {
            if(!root) return;
            curNum = curNum*10 + root->val;
            if(!root->left && !root->right) sum += curNum;
            generateSum(root->left, curNum, sum);
            generateSum(root->right, curNum, sum);
        };

public:
    int sumNumbers(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        int sum = 0;
        generateSum(root, 0, sum);
        return sum;
    }
};
