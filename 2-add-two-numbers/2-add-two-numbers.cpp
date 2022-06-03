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
    ListNode *fun(ListNode* l1, ListNode* l2,int x){
        if(l1==NULL && l2==NULL){
            if(x!=0){
                ListNode *n=new ListNode(x);
                return n;
            }
            else{
                return NULL;
            }
        }
        if(l1!=NULL && l2==NULL){
            int s=l1->val+x;
            l1->val=s%10;
            l1->next=fun(l1->next,l2,s/10);
            return l1;
        }
        if(l1==NULL && l2!=NULL){
            int s=l2->val+x;
            l2->val=s%10;
            l2->next=fun(l1,l2->next,s/10);
            return l2;
        }
        if(l1!=NULL && l2!=NULL){
            int s=l1->val+l2->val+x;
            l1->val=s%10;
            l1->next=fun(l1->next,l2->next,s/10);
            return l1;
        }
        return NULL;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return fun(l1,l2,0);
    }
};