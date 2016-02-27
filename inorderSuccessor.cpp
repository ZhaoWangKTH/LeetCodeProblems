// Leetcode problem/inorderSuccessor.cpp

/* Problem Statement: given a value and BST, find the value's inroder successor in the BST */
/* For example: A BST as follows
                5
               / \
			        3   10
             / \   \
            1   4   11
             \
              2
              
  The inorder successor of 2 is 3, of 3 is 4, of 4 is 5. (the next greater value)            
*/


/* Solution: 
    case 1: if the value does not exist, output NULL
    case 2: if the value is found:
         2a: if its right-leaf exists, the desired output is the minimum of its right tree
         2b: if its right-leaf does not exist, the desired output is its first ancestor that itself is a left-leaf. If this node does not             exist, output NULL.
         
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

TreeNode* findItsParent(TreeNode* root, int value) {
    if(root == NULL)
        return NULL;
    
    TreeNode *parent = NULL;
    TreeNode *curNode = root;
    while(curNode != NULL) {
        if(curNode->val == value) // found it
            return parent;
        else if(curNode->val > value) {
            parent = curNode;
            curNode = curNode->left;
        }
        else {
            parent = curNode;
            curNode = curNode->right;
        }
    }
    
    return NULL;
} 

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == NULL)
        return NULL;
        
    TreeNode *parent = findItsParent(A, B);
    if(parent == NULL && A->val != B) {
        // B doest not exist in the tree
        return NULL;
    }
    else if(parent == NULL) {
        // found the value in the root
        parent = A;
        TreeNode* curNode = A->right;
        if(curNode == NULL)
            return NULL;
        else {
            while(curNode != NULL) {
                parent = curNode;
                curNode = curNode->left;
            }
            return parent;
        }    
    }
    
    
    // found the node, and meanwhile its parent is not NULL
    TreeNode* curNode;
    bool leftLeaf;
    if(parent->left != NULL && parent->left->val == B) {
        curNode = parent->left;
        leftLeaf = true;
    }
    else {
        curNode = parent->right;
        leftLeaf = false;
    }
    
    if(curNode->right != NULL) {
        curNode = curNode->right;
        while(curNode != NULL) {
            parent = curNode;
            curNode = curNode->left;
        }
        return parent;
    }
    else {  // its right leaf is null, go up to its parent
        if(leftLeaf == true)
            return parent;
        else {
            while(parent != NULL) {
                int curValue = parent->val;
                parent = findItsParent(A, curValue);
                if(parent == NULL)
                    return NULL;
                else if(parent->val > curValue)
                    return parent;
            }
            return NULL;
        }
            
    }
}
