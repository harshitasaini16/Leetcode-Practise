class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guard, vector<vector<int>>& walls) {
        map<pair<int,int>,int>w;
        vector<vector<int>>mat(n,vector<int>(m,1));
        for(int i=0;i<guard.size();i++){
            int x=guard[i][0];
            int y=guard[i][1];
            mat[x][y]=2;
        }
        for(int i=0;i<walls.size();i++){
            int x=walls[i][0];
            int y=walls[i][1];
            mat[x][y]=-2;
        }
        for(int i=0;i<guard.size();i++){
            int x=guard[i][0];
            int y=guard[i][1];
            int j=y-1;
            while(j>=0 && mat[x][j]!=2 && mat[x][j]!=-2){
                mat[x][j]=0;
                j--;
            }
            j=y+1;
            while(j<m && mat[x][j]!=2 && mat[x][j]!=-2){
                mat[x][j]=0;
                j++;
            }
            int k=x-1;
            while(k>=0 && mat[k][y]!=2 && mat[k][y]!=-2){
                mat[k][y]=0;
                k--;
            }
            k=x+1;
            while(k<n && mat[k][y]!=2 && mat[k][y]!=-2){
                mat[k][y]=0;
                k++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};