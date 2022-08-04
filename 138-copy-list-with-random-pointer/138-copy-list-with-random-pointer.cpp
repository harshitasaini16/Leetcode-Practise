/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *h=head;
        while(h!=NULL){
            Node *n=new Node(h->val);
            n->next=h->next;
            h->next=n;
            h=h->next->next;
        }
        h=head;
        while(h!=NULL && h->next!=NULL){
            if(h->random==NULL){
                h->next->random=NULL;
            }
            else{
                h->next->random=h->random->next;
            }
            h=h->next->next;
        }
        if(head==NULL){
            return NULL;
        }
        Node *ans=head->next;
        Node *temp=head->next;
        while(head!=NULL){
            head->next=temp->next;
            head=head->next;
            if(head==NULL) break;
            temp->next=head->next;
            temp=temp->next;
        }
        return ans;
    }
};