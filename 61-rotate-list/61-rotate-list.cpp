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
    int size(ListNode *head){
        if(head==NULL){
            return 0;
        }
        return 1+size(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *p=head;
        int n=size(head);
        k=k%n;
        if(k==0){
            return head;
        }
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && k>0){
            fast=fast->next;
            k--;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        head=slow->next;
        ListNode *s=head;
        slow->next=NULL;
        while(s->next!=NULL){
            s=s->next;
        }
        s->next=p;
        return head;
    }
};