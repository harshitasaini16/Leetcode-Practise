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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode *h=head;
        while(h!=NULL){
            n++;
            h=h->next;
        }
        if(n<k){
            return head;
        }
        ListNode *curr=head,*prev=NULL,*nxt=NULL;
        int i=0;
        while(curr!=NULL && i<k){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            i++;
        }
        if(curr==NULL){
            return prev;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};