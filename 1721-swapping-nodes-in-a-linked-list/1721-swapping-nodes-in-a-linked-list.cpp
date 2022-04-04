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
    ListNode *front(ListNode *node,int k){
        while(node!=NULL && k>1){
            node=node->next;
            k--;
        }
        return node;
    }
    ListNode *back(ListNode *node,int k){
        ListNode *p=node;
        while(node!=NULL && k>1){
            node=node->next;
            k--;
        }
        while(node->next!=NULL){
            node=node->next;
            p=p->next;
        }
        return p;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        auto x=front(head,k);
        cout<<x->val;
        cout<<endl;
        auto y=back(head,k);
        cout<<y->val;
        swap(x->val,y->val);
        return head;
    }
};