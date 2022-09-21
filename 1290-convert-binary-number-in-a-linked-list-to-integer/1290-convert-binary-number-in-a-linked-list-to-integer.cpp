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
    int x;
    int fun(ListNode* head){
        if(head==NULL){
            return 0;
        }
        if(head->next==NULL){
            int ans=pow(2,x)*head->val;
            x++;
            return ans;
        }
        int s1=fun(head->next);
        int s2=pow(2,x)*head->val;
        x++;
        return s1+s2;
    }
    int getDecimalValue(ListNode* head) {
        x=0;
        return fun(head);
    }
};