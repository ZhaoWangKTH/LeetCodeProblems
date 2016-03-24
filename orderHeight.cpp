//Leetcode problems/orderHeight.cpp

/* Problem statement: Order of people heights
You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.*/

/* Solution: Using Rope data structure, which contains a value and an index. An index is used to save the number of nodes in its left tree + itself (1). For every new node to insert, compare its index to the index of each node in the tree. If index is bigger, go left. Otherwise, update its index = index - (the index of the node compared) and go right. 
  When finally found its position, insert and set its index as 1, (its value remains during the whole time).
  
  the last step: inorder traversal the tree
*/  
  

#include <queue>

struct ropeNode{
    int value;
    int index;
    ropeNode *left;
    ropeNode *right;
    ropeNode(int v=0, int id=1): value(v), index(id) {left = NULL; right=NULL;}
};

ropeNode* insertNode(ropeNode* root, int value, int index) {
    if(root==NULL) {
        ropeNode *newRoot = new ropeNode(value, 1);
        return newRoot;
    }
        
    ropeNode* curNode = root;
    while(curNode != NULL) {
        if(curNode->index > index) {
            curNode->index += 1;
            if(curNode->left != NULL)
                curNode = curNode->left;
            else 
            {
                curNode->left = new ropeNode(value, 1);
                break;
            }
        }
        else {
            index = index - curNode->index;
            if(curNode->right != NULL)
                curNode = curNode->right;
            else
            {
                curNode->right = new ropeNode(value, 1);
                break;
            }
        }
    }
    
    return root;
}

void inorderTraversal(ropeNode* root, vector<int> &result) {
    if(root==NULL)
        return;
    inorderTraversal(root->left, result);
    result.push_back(root->value);
    inorderTraversal(root->right, result);
    
    return;
}

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    
    if(heights.size()==0)
        return result;
    
    // max heap    
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::less<pair<int,int>> > htQue;
    
    for(int i=0; i<heights.size(); i++)
        htQue.push(make_pair(heights[i], infronts[i]));
    
    ropeNode *root = insertNode(NULL, htQue.top().first, htQue.top().second);
    htQue.pop();
    
    for(int i=1; i<heights.size(); i++) {
        root = insertNode(root, htQue.top().first, htQue.top().second);
        htQue.pop();
    }
    
    inorderTraversal(root, result);
    return result;
}
