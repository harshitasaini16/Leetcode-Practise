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
    ListNode *merge(ListNode *h1,ListNode *h2){
        if(h1==NULL && h2==NULL){
            return NULL;
        }
        if(h1==NULL){
            return h2;
        }
        if(h2==NULL){
            return h1;
        }
        if(h1->val<h2->val){
            h1->next=merge(h1->next,h2);
            return h1;
        }
        h2->next=merge(h1,h2->next);
        return h2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode* head=lists[0];
        for(int i=1;i<lists.size();i++){
            head=merge(lists[i],head);
        }
        return head;
    }
};