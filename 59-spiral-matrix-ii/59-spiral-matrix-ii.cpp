class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        int l=0,r=n-1,u=0,d=n-1;
        int x=1;
        int y=0;
        while(l<=r && u<=d){
            if(y==0){
                for(int i=l;i<=r;i++){
                   mat[u][i]=x;
                   x++;
                }
                u++;
                y++;
            }
            else if(y==1){
                for(int i=u;i<=d;i++){
                   mat[i][r]=x;
                   x++;
                }
                r--;
                y++;
            }
            else if(y==2){
                for(int i=r;i>=l;i--){
                   mat[d][i]=x;
                   x++;
                }
                d--;
                y++;
            }
            else if(y==3){
                for(int i=d;i>=u;i--){
                   mat[i][l]=x;
                   x++;
                }
                l++;
                y=0;
            }
        }
        return mat;
    }
};