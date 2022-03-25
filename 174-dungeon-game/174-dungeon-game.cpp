class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>&mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    mat[i][j]=mat[i][j];
                }
                else if(i==n-1){
                    mat[i][j]+=mat[i][j+1];
                }
                else if(j==m-1){
                    mat[i][j]+=mat[i+1][j];
                }
                else{
                    mat[i][j]+=max(mat[i+1][j],mat[i][j+1]);
                }
                if(mat[i][j]>0){
                    mat[i][j]=0;
                }
            }
        }
        return abs(mat[0][0])+1;
    }
};