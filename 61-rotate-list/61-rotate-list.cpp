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
    int size(ListNode* head){
        if(head==NULL){
            return 0;
        }
        return 1+size(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int n=size(head);
        k=k%n;
        if(k==0){
            return head;
        }
        k=n-k;
        ListNode *h=head;
        while(k>1 && h!=NULL){
            k--;
            h=h->next;
        }
        ListNode *kp=h->next;
        ListNode *lh=h->next;
        while(kp->next!=NULL){
            kp=kp->next;
        }
        kp->next=head;
        h->next=NULL;
        return lh;
    }
};