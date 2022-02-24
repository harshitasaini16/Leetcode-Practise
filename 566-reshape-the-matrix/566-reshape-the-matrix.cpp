class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat[0].size()*mat.size()!=r*c){
            return mat;
        }
        vector<vector<int>>v;
        int p=0;
        vector<int>k;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                k.push_back(mat[i][j]);
                p++;
                if(p==c){
                    v.push_back(k);
                    p=0;
                    k.clear();
                }
            }
        }
        return v;
    }
};