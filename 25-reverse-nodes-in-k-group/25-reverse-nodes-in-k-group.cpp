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
    int len(ListNode *head){
        int x=0;
        while(head!=NULL){
            head=head->next;
            x++;
        }
        return x;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=len(head);
        if(n<k){
            return head;
        }
        ListNode *prev=NULL;
        ListNode *next=NULL;
        ListNode *curr=head;
        int i=0;
        while(curr!=NULL && i<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};