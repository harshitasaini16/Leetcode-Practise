class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int l=0,u=0,d=n-1,r=n-1;
        int y=0;
        int x=1;
        while(l<=r && u<=d){
            if(y==0){
                for(int i=l;i<=r;i++){
                    ans[u][i]=x;
                    x++;
                }
                u++;
                y++;
            }
            else if(y==1){
                for(int i=u;i<=d;i++){
                    ans[i][r]=x;
                    x++;
                }
                r--;
                y++;
            }
            else if(y==2){
                for(int i=r;i>=l;i--){
                    ans[d][i]=x;
                    x++;
                }
                d--;
                y++;
            }
            else if(y==3){
                for(int i=d;i>=u;i--){
                    ans[i][l]=x;
                    x++;
                }
                l++;
                y=0;
            }
        }
        return ans;
    }
};