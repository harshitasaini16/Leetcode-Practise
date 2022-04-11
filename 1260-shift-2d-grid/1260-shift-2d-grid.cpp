class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        while(k--){
            int x=grid[n-1][m-1];
            int y;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==0 && j==0){
                        y=grid[i][j];
                    }
                    else{
                        int z=grid[i][j];
                        grid[i][j]=y;
                        y=z;
                    }
                }
            }
            grid[0][0]=x;
        }
        return grid;
    }
};