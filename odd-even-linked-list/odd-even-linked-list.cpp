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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *temp=head;
        ListNode *head1=head,*head2=head->next;
        ListNode *temp1=head1,*temp2=head2;
        temp=temp->next->next;
        while(temp!=NULL){
            if(temp->next==NULL){
                temp1->next=temp;
                temp=temp->next;
                temp1=temp1->next;
            }
            else{
                temp1->next=temp;
                temp2->next=temp->next;
                temp=temp->next->next;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        temp1->next=NULL;
        temp2->next=NULL;
        temp1->next=head2;
        return head1;
    }
};