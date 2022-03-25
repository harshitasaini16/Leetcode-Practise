class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==0){
                    mat[i][j]+=min(mat[i+1][j],mat[i+1][j+1]);
                }
                else if(j==m-1){
                    mat[i][j]+=min(mat[i+1][j],mat[i+1][j-1]);
                }
                else{
                    mat[i][j]+=min({mat[i+1][j],mat[i+1][j+1],mat[i+1][j-1]});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<mat[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,mat[0][i]);
        }
        return ans;
    }
};