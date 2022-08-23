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
    bool fun(ListNode *h1,ListNode *h2){
        if(h1==NULL && h2==NULL){
            return true;
        }
        if(h1==NULL || h2==NULL){
            return true;
        }
        ListNode *curr=h2,*prev=NULL,*nxt=NULL;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        while(prev!=NULL){
            if(prev->val!=h1->val){
                return false;
            }
            prev=prev->next;
            h1=h1->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return fun(head,slow);
    }
};