class Solution {
public:
    int dx[8]={1,-1,-1,1,0,1,0,-1};
    int dy[8]={1,1,-1,-1,1,0,-1,0};
    void gameOfLife(vector<vector<int>>& b) {
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int av=0;
                for(int k=0;k<8;k++){
                    int xx=dx[k]+i;
                    int yy=dy[k]+j;
                    if(xx<n && yy<m && xx>=0 && yy>=0 && (b[xx][yy]==1 || b[xx][yy]==3)){
                        av++;
                    }
                }
                if(b[i][j]==1){
                    if(av<2){
                        b[i][j]=3;
                    }
                    else if(av>3){
                        b[i][j]=3;
                    }
                }
                else if(b[i][j]==0){
                    if(av==3){
                        b[i][j]=2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==2){
                    b[i][j]=1;
                }
                else if(b[i][j]==3){
                    b[i][j]=0;
                }
            }
        }
    }
};