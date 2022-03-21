class Solution {
public:
    int numDistinct(string s, string t) {
        int mod=1e9+7;
        int n=s.length();
        int m=t.length();
        int mat[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0){
                    mat[i][j]=1;
                }
                else if(i==0){
                    mat[i][j]=0;
                }
                else if(j==0){
                    mat[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    mat[i][j]=(mat[i-1][j-1]+mat[i-1][j])%mod;
                }
                else{
                    mat[i][j]=mat[i-1][j];
                }
            }
        }
        return mat[n][m];
    }
};