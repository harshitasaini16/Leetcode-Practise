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
        Node *temp1=head;
        Node *temp2=head->next;
        head=head->next;
        while(temp1!=NULL){
            temp1->next=temp2->next;
            temp1=temp1->next;
            if(temp1==NULL){
                break;
            }
            temp2->next=temp1->next;
            temp2=temp2->next;
        }
        return head;
    }
};