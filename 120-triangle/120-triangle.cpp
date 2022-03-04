class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<tri[i].size();j++){
                if(j==0){
                    tri[i][j]+=tri[i-1][j];
                }
                else if(j==tri[i].size()-1){
                    tri[i][j]+=tri[i-1][j-1];
                }
                else{
                    tri[i][j]+=min(tri[i-1][j],tri[i-1][j-1]);
                }
            }
        }
        int mx=INT_MAX;
        for(int j=0;j<tri[n-1].size();j++){
            mx=min(mx,tri[n-1][j]);
        }
        return mx;
    }
};