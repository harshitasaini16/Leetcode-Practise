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
        ListNode *slow=head,*fast=head;
        while(slow!=NULL && fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *curr=slow,*prev=NULL,*nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        int ans=0;
        while(prev!=NULL){
            ans=max(ans,prev->val+head->val);
            head=head->next;
            prev=prev->next;
        }
        return ans;
    }
};