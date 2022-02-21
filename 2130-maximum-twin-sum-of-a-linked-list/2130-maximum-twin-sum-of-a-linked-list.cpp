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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        int sze=0;
        while(temp!=nullptr){
            temp=temp->next;
            sze++;
        }
        
        int arr[sze];
        
        for(int i=0;i<sze;i++){
            arr[i]=head->val;
            head=head->next;
        }
        
        int lo=0,hi=sze-1;
        int mx=0;
        while(lo<hi){
            int sum=arr[lo]+arr[hi];
            mx=max(sum,mx);
            lo++;
            hi--;
        }
        return mx;
    }
};