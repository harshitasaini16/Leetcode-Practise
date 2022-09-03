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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>q;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                q.push({lists[i]->val,lists[i]});
            }
        }
        ListNode *head=NULL;
        ListNode *temp=NULL;
        while(!q.empty()){
            ListNode* x=q.top().second;
            q.pop();
            if(head==NULL){
                head=x;
                temp=head;
                if(x->next!=NULL){
                    q.push({x->next->val,x->next});
                }
            }
            else{
                temp->next=x;
                temp=temp->next;
                if(x->next!=NULL){
                    q.push({x->next->val,x->next});
                }
            }
        }
        return head;
    }
};