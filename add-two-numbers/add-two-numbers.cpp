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
    ListNode* fun(ListNode *l1,ListNode *l2,int c){
        if(l1==NULL && l2==NULL){
            if(c==0){
                return NULL;
            }
            ListNode *n=new ListNode(c);
            return n;
        }
        if(l1==NULL){
            int x=l2->val+c;
            l2->val=x%10;
            l2->next=fun(l1,l2->next,x/10);
            return l2;
        }
        if(l2==NULL){
            int x=l1->val+c;
            l1->val=x%10;
            l1->next=fun(l1->next,l2,x/10);
            return l1;
        }
        int x=l1->val+l2->val+c;
        l1->val=x%10;
        l1->next=fun(l1->next,l2->next,x/10);
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return fun(l1,l2,0);
    }
};