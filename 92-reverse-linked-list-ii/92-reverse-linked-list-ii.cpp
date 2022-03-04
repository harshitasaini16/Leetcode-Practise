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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode *h=head;
        if(left==1){
            ListNode *f=head;
            int j=0;
            while(j<right){
                j++;
                f=f->next;
            }
            ListNode *g=h;
            ListNode *curr=g,*next=NULL,*prev=NULL;
            while(curr!=f){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            if(curr==NULL){
                return prev;
            }
            ListNode *u=head;
            u->next=curr;
            return prev;
        }
        else if(left>1){
            int i=2;
            while(h!=NULL && i<left){
                h=h->next;
                i++;
            }
            ListNode *f=head;
            int j=0;
            while(j<right){
                j++;
                f=f->next;
            }
            ListNode *g=h->next;
            ListNode *curr=g,*next=NULL,*prev=NULL;
            while(curr!=f){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            g->next=curr;
            h->next=prev;
            return head;
        }
        return NULL;
    }
};