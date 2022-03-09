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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *h1=head;
        ListNode *h2=head->next;
        int c=h1->val;
        if(h2->val!=c){
            h1->next=deleteDuplicates(h2);
            return h1;
        }
        else{
            while(h1!=NULL && h1->val==c){
                h1=h1->next;
            }
            return deleteDuplicates(h1);
        }
    }
};