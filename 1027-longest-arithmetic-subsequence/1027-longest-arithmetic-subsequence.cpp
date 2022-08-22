class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n=a.size();
        int ans=0;
        int mx=0;
        vector<vector<int>>m(n,vector<int>(2000,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int x=a[i]-a[j]+1000;
                m[i][x]=max(m[i][x],m[j][x]+1);
                mx=max(m[i][x],mx);
            }
        }
        return mx+1;
    }
};