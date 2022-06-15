class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=m-1,u=0,d=n-1;
        int x=0;
        while(l<=r && u<=d){
            if(x==0){
                for(int i=l;i<=r;i++){
                    ans.push_back(mat[u][i]);
                }
                u++;
                x++;
            }
            else if(x==1){
                for(int i=u;i<=d;i++){
                    ans.push_back(mat[i][r]);
                }
                r--;
                x++;
            }
            else if(x==2){
                for(int i=r;i>=l;i--){
                    ans.push_back(mat[d][i]);
                }
                d--;
                x++;
            }
            else if(x==3){
                for(int i=d;i>=u;i--){
                    ans.push_back(mat[i][l]);
                }
                l++;
                x=0;
            }
        }
        return ans;
    }
};