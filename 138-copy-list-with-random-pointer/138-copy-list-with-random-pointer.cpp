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
        if(head==NULL){
            return NULL;
        }
        Node *temp=head;
        while(temp!=NULL){
            Node *n=new Node(temp->val);
            n->next=temp->next;
            temp->next=n;
            temp=n->next;
        }
        Node *h=head->next;
        Node *n1=head;
        while(n1!=NULL){
            if(n1->random!=NULL){
                n1->next->random=n1->random->next;
            }
            n1=n1->next->next;
        }
        n1=head;
        Node *n2=head->next;
        while(n1!=NULL && n2!=NULL){
            n1->next=n2->next;
            n1=n1->next;
            if(n1==NULL){
                break;
            }
            n2->next=n1->next;
            n2=n2->next;
        }
        return h;
    }
};