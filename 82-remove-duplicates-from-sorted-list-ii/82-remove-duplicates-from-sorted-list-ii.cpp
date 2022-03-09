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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* dummy = new ListNode; 
  
   
    dummy -> next = head; 
      
    
    ListNode* prev = dummy; 
      
    
    ListNode* current = head; 
  
    while(current != NULL) 
    { 
       
        
        while(current -> next != NULL && 
              prev -> next -> val == current -> next -> val) 
            current = current -> next; 
  
        
        if (prev -> next == current) 
            prev = prev -> next; 
  
         
        else
            prev -> next = current -> next; 
  
        current = current -> next; 
    } 
  
    
    head = dummy -> next; 
        return head;
    }
};