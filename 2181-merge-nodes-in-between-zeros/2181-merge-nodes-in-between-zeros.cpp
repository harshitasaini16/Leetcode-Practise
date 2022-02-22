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
    ListNode *fun(ListNode *head){
        if(head==NULL){
            return NULL;
        }
        int s=0;
        while(head->val!=0){
            s+=head->val;
            head=head->next;
        }
        ListNode *n=new ListNode(s);
        n->next=fun(head->next);
        return n;
    }
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        return fun(head->next);
    }
};