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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool fun(ListNode* head, TreeNode* root){
        if(head==NULL && root==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(head==NULL){
            return true;
        }
        if(head->val!=root->val){
            return false;
        }
        return (fun(head->next,root->left) || fun(head->next,root->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==NULL && root==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(head==NULL){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *h=q.front();
            q.pop();
            if(fun(head,h)){
                return true;
            }
            if(h->left!=NULL){
                q.push(h->left);
            }
            if(h->right!=NULL){
                q.push(h->right);
            }
        }
        return false;
    }
};