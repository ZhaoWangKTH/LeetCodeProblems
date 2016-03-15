// Leetcode problems/mergeKSortList_II.cpp

/* Merge K sorted lists */

/* Solution: Similar to merge sort. Based on the method merge two sorted list, every time we merge two lists until only one sorted list is left. Time complexity O(n KlogK), space complexity O(1).*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private: 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        
        ListNode* cand1 = l1;
        ListNode* cand2 = l2;
        
        while(cand1!=NULL && cand2!=NULL) {
            if(cand1->val < cand2->val) {
                cur->next = cand1;
                cand1 = cand1->next;
                cur = cur->next;
            }
            else {
                cur->next = cand2;
                cand2 = cand2->next;
                cur = cur->next;
            }
        }
        
        if(cand1 == NULL)
            cur->next = cand2;
        else
            cur->next = cand1;
            
        return dummy.next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
            
        int begin = 0;
        int end = lists.size()-1;
        
        while(end > 0) {
            begin = 0;
            while(begin < end) {
                // merge two list at begin and end
                lists[begin] = mergeTwoLists(lists[begin], lists[end]);
                begin++;
                end--;
            }
        }
        
        return lists[0];
    }
};
