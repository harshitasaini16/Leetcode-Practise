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
    ListNode*fun(ListNode*p1){
        ListNode*curr=p1,*nextt=p1,*prev=NULL;
        while(nextt!=NULL){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return;
        }
        ListNode*p1=head,*p2=head->next;
        while(p2!=NULL and p2->next!=NULL){
            p1=p1->next;
            p2=p2->next->next;
        }
        p2=p1->next;
        p1->next=NULL;
        p2=fun(p2);
        for (p1 = head ; p1; ) {
            auto t = p1->next;
            p1 = p1->next = p2;
            p2 = t;
        }
    }
};