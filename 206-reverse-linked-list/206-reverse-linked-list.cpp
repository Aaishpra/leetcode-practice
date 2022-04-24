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
    ListNode* reverseList(ListNode* head) {
        //Iterative solution
    ListNode* prev=NULL, *n=NULL;
        while(head){
            //store the value of n
            n=head->next;
            //reverse the link
            head->next=prev;
            //Move Pointer
            prev=head;
            head=n;
        }
        return prev;
    }
};