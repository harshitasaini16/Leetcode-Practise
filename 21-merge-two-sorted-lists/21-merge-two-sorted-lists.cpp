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
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
        if(List1==NULL && List2==NULL){
            return NULL;
        }
        if(List1==NULL && List2!=NULL){
            return List2;
        }
        if(List1!=NULL && List2==NULL){
            return List1;
        }
        if(List1->val<List2->val){
            List1->next=mergeTwoLists(List1->next,List2);
            return List1;
        }
         List2->next=mergeTwoLists(List1,List2->next);
            return List2;
    }
};