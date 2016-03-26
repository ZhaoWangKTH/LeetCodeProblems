//Leetcode Problems/connectBST.cpp

/* Problem Statement: Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
Example :

Given the following perfect binary tree,

         1
       /  \
      2    5
     / \  / \
    3  4  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 5 -> NULL
     / \  / \
    3->4->6->7 -> NULL
Note that using recursion has memory overhead and does not qualify for constant space.*/

/* Solution: Mark the current level head and the prev level head. Going through every level. */


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(!A)
        return;
    
    A->next = NULL;
    // initialization
    
    TreeLinkNode* prevLayerHead = A;
    TreeLinkNode* curLayerHead = prevLayerHead->left;
    TreeLinkNode* prevLayerNode = prevLayerHead;
    TreeLinkNode* curLayerNode = curLayerHead;
    
    while(prevLayerNode!=NULL) {
        if(curLayerNode!=NULL) {
            curLayerNode->next = prevLayerNode->right;
            curLayerNode = curLayerNode->next;
            // update prevLayer
            prevLayerNode = prevLayerNode->next;
            if(prevLayerNode!=NULL) {
                curLayerNode->next = prevLayerNode->left;
                curLayerNode = curLayerNode->next;
            }
            else {
                curLayerNode->next = NULL;
                // go to next layer
                prevLayerHead = curLayerHead;
                curLayerHead = prevLayerHead->left;
                // set the current node
                prevLayerNode = prevLayerHead;
                curLayerNode = curLayerHead;
            }    
        }
        else
            break;
    }
    
    return;
}
