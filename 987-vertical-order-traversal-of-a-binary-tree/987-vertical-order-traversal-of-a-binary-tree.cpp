class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>m;
        queue<pair<TreeNode*,int>>s;
        s.push({root,0});
        int y=0;
        while(!s.empty()){
            int size=s.size();
            while(size--){
                TreeNode *n=s.front().first;
                int x=s.front().second;
                m[x][y].push_back(n->val);
                s.pop();
                if(n->left!=NULL){
                    s.push({n->left,x-1});
                }
                if(n->right!=NULL){
                    s.push({n->right,x+1});
                }
            }
            y++;
        }
        vector<vector<int>>ans;
        for(auto i:m){
            map<int,vector<int>> n=i.second;
            vector<int>v;
            for(auto j:n){
                sort(j.second.begin(),j.second.end());
                v.insert(v.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};