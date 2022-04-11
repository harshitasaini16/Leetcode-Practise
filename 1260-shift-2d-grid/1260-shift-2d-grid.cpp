class Solution {
public:
    void reverse(vector<vector<int>>& grid,int l,int r){
        int n=grid.size();
        int m=grid[0].size();
        while(l<r){
            int lr=l/m,lc=l%m;
            int rr=r/m,rc=r%m;
            if(rr==n){
                rr=0;
            }
            swap(grid[lr][lc],grid[rr][rc]);
            l++;
            r--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k=k%(n*m);
        reverse(grid,0,n*m-1);
        reverse(grid,0,k-1);
        reverse(grid,k,n*m-1);
        return grid;
    }
};