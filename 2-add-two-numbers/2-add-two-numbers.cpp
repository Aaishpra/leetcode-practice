/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int left = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        
        while(!(l1 == nullptr && l2 == nullptr && left == 0)){
           
            int add1 = l1 != nullptr ? l1->val : 0;
            
            int add2 = l2 != nullptr ? l2->val : 0;
            int sum = add1 + add2 + left;
            left = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = newNode;
            
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        
        return dummy->next;
    }
};