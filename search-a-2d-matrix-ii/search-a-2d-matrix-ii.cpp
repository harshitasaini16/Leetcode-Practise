class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        int x=0;
        int y=m-1;
        while(x>=0 && y>=0 && x<n && y<m){
            if(mat[x][y]==target){
                return true;
            }
            else if(mat[x][y]>target){
                y--;
            }
            else{
                x++;
            }
        }
        return false;
    }
};