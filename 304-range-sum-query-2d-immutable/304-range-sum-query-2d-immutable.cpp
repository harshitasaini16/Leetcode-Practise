class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<=n;i++){
            vector<int>v;
            for(int j=0;j<=m;j++){
                v.push_back(0);
            }
            mat.push_back(v);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mat[i][j]=mat[i-1][j]+mat[i][j-1]+matrix[i-1][j-1]-mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s=mat[row2+1][col2+1]-mat[row2+1][col1]-mat[row1][col2+1]+mat[row1][col1];
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */