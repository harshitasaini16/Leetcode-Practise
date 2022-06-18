class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>ans;
        int mx=-1;
        vector<int>v;
        sort(in.begin(),in.end());
        for(int i=0;i<in.size();i++){
            if(mx==-1){
                v.push_back(in[i][0]);
                mx=in[i][1];
            }
            else{
                if(in[i][0]>mx){
                    v.push_back(mx);
                    ans.push_back(v);
                    v.clear();
                    v.push_back(in[i][0]);
                    mx=in[i][1];
                }
                else{
                    mx=max(mx,in[i][1]);
                }
            }
        }
        v.push_back(mx);
        ans.push_back(v);
        return ans;
    }
};