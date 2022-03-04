class Solution {
public:
    double champagneTower(int poured, int qr, int qg) {
        vector<vector<double>>v(qr+2,vector<double>(qg+2,0));
        v[0][0]=poured;
        for(int i=0;i<=qr;i++){
            for(int j=0;j<=qg;j++){
                double x=(v[i][j]-1.0)/2;
                if(x>0){
                    v[i+1][j]+=x;
                    v[i+1][j+1]+=x;
                }
            }
        }
        return min(1.0,v[qr][qg]);
    }
};