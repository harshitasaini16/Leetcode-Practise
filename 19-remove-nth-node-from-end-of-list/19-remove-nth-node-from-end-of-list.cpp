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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *h=head;
        int i=0;
        while(i<n && h!=NULL){
            h=h->next;
            i++;
        }
        if(h==NULL){
            return head->next;
        }
        ListNode *l=head;
        while(h->next!=NULL){
            h=h->next;
            l=l->next;
        }
        l->next=l->next->next;
        return head;
    }
};