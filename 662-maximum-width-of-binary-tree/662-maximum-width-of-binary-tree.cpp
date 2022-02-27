class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,long long  >>q;
        q.push({root,0});
        long long ans=1;
        while(!q.empty()){
            long long k=q.size();
            long long  minn=q.front().second;
            long long f,l;
            for(int i=0;i<k;i++){
                long long id=q.front().second-minn;
                TreeNode*tt=q.front().first;
                q.pop();
                if(i==0){
                    f=id;
                }
                if(i==k-1){
                    l=id;
                }
                if(tt->left){
                    q.push({tt->left,2*id +1});
                }
                if(tt->right){
                    q.push({tt->right,2*id +2});
                }
            }
            ans=max(ans,(l-f)+1);
        }
        return (int)ans;
    }
};