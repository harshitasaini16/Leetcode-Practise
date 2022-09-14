class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>>ans;
        int n=in.size();
        int x=in[0][1];
        vector<int>v;
        v.push_back(in[0][0]);
        for(int i=1;i<n;i++){
            if(x<in[i][0]){
                v.push_back(x);
                ans.push_back(v);
                v.clear();
                v.push_back(in[i][0]);
                x=in[i][1];
            }
            else{
                x=max(x,in[i][1]);
            }
        }
        v.push_back(x);
        ans.push_back(v);
        return ans;
    }
};