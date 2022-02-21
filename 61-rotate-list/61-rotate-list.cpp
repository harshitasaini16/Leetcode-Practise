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
        int n=size(head);
        if(n==0){
            return NULL;
        }
        k=k%n;
        if(k==0){
            return head;
        }
        int p=(n-k);
        ListNode *h=head;
        while(p>1){
            h=h->next;
            p--;
        }
        ListNode *hd=h->next;
        ListNode *t=h;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=head;
        h->next=NULL;
        return hd;
    }
};