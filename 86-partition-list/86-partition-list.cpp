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
    ListNode* partition(ListNode* head, int x) {
        vector<int>v;
        ListNode *h=head;
        while(h!=NULL){
           if(h->val<x){
               v.push_back(h->val);
           }
           h=h->next;
        }
        h=head;
        while(h!=NULL){
           if(h->val>=x){
               v.push_back(h->val);
           }
           h=h->next;
        }
        h=head;
        int i=0;
        while(h!=NULL){
            h->val=v[i];
            i++;
            h=h->next;
        }
        return head;
    }
};