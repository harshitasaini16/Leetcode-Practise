class NumMatrix {
public:
    int n,m;
    vector<vector<int>>sum;
    NumMatrix(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        for(int i=0;i<=n;i++){
            vector<int>v;
            for(int j=0;j<=m;j++){
                v.push_back(0);
            }
            sum.push_back(v);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i-1][j-1];
                cout<<sum[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        r1++;
        r2++;
        c1++;
        c2++;
        return sum[r2][c2]-sum[r2][c1-1]-sum[r1-1][c2]+sum[r1-1][c1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */