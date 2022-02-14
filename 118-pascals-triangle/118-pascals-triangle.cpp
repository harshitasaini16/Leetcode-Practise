class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            if(i==1){
                ans.push_back({1});
            }
            else{
                vector<int>v;
                v.push_back(1);
                for(int j=0;j<ans[ans.size()-1].size()-1;j++){
                    v.push_back(ans[ans.size()-1][j]+ans[ans.size()-1][j+1]);
                }
                v.push_back(1);
                ans.push_back(v);
             }
         }
        return ans;
    }
};