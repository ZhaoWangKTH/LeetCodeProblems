//Leetcode Problems/shortestPrefix.cpp

/* Problem Statement: Shortest Unique PrefixBookmark
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov 
*/

/* Solution: Using the data structure Trie. The above example can be modeled as the following Trie structure:
                           root
                          /    \
                        z,1     d,3
                        /      /   \
                      e,1    o,2    u,1
                     /       / \      \
                  b,1      g,1  t,1    c,1
                 /      (dog)   (dot)   \
              r,1                        k,1
              /                         (duck)
            a,1
          (zebra)
  For each string, the shortest prefix is the first freq==1 in the path.           
            
*/


#define MAX 26

// Trie Node.
struct trieNode
{
    char letter; // to store letter
    int freq;  // To store frequency
    vector<trieNode*> child;
    
    // construction function
    trieNode(int f=1, char c=0): freq(f), letter(c) {
        child = vector<trieNode*> (MAX, NULL);      
    }
};
 

// Method to insert a new string into Trie
void insert(trieNode *root, string str)
{
    // Length of the URL
    int len = str.length();
    trieNode *pCrawl = root;
 
    // Traversing over the length of given str.
    for (int level = 0; level<len; level++)
    {
        // Get index of child node from current character
        // in str.
        int index = str[level] - 'a';
 
        // Create a new child if not exist already
        if (!pCrawl->child[index])
            pCrawl->child[index] = new trieNode(1,index);
        else
           (pCrawl->child[index]->freq)++;
 
        // Move to the child
        pCrawl = pCrawl->child[index];
    }
}
 
// This function prints unique prefix for every word stored
// in Trie. Prefixes one by one are stored in prefix[].
// 'ind' is current index of prefix[]
string findPrefixes(trieNode *root, string &target) {
    string result;
    if(!root)
        return result;
    
    int len = target.length();
    trieNode *curNode = root;
    
    for(int level=0; level <len; level++) {
        int curChar = target[level] - 'a';
        result.push_back(curChar+'a');
        curNode = curNode->child[curChar];
        if(curNode->freq != 1)
            continue;
        else
            break;
    }
    return result;
}
 

vector<string> Solution::prefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // Construct a Trie of all words
    trieNode *root = new trieNode();
    root->freq = 0;
    for (int i = 0; i<A.size(); i++)
        insert(root, A[i]);
 
    vector<string> result;
    for(int i=0; i<A.size();i++)
        result.push_back(findPrefixes(root, A[i]));
        
    return result;    
}
