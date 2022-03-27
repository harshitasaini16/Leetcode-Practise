class Solution {
public:
    static bool cmp(vector<int>v1,vector<int>v2){
        if(v1[0]<v2[0]){
            return true;
        }
        else if(v1[0]==v2[0]){
            if(v1[1]<v2[1]){
                return true;
            }
        }
        return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>>v;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<m;j++){
                s+=mat[i][j];
            }
            v.push_back({s,i});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i][1]);
        }
        return ans;
    }
};