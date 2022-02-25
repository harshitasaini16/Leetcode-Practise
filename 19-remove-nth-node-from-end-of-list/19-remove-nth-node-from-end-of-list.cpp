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
            i++;
            h=h->next;
        }
        if(h==NULL){
            return head->next;
        }
        ListNode *h2=head;
        while(h->next!=NULL){
            h2=h2->next;
            h=h->next;
        }
        h2->next=h2->next->next;
        return head;
    }
};