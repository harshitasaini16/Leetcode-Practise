class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pref(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s1=((i-1)>=0)?pref[i-1][j]:0;
                int s2=((j-1)>=0)?pref[i][j-1]:0;
                int s3=((i-1)>=0 && (j-1)>=0)?pref[i-1][j-1]:0;
                pref[i][j]=mat[i][j]+s1+s2-s3;
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0; k+i<n && k+j<m; k++){
                    int s1=(i>0)?pref[i-1][j+k]:0;
                    int s2=(j>0)?pref[i+k][j-1]:0;
                    int s3=(i>0 && j>0)?pref[i-1][j-1]:0;
                    int sum=pref[i+k][j+k]-s1-s2+s3;
                    if(sum<=threshold){
                        mx=max(mx,k+1);
                    }
                }
            }
        }
        return mx;
    }
};