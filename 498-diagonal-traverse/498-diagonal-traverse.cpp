class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        int turn=0;
        for(int i=0;i<n;i++){
            int x=i;
            int y=0;
            vector<int>v1;
            while(x>=0 && y<m){
                v1.push_back(mat[x][y]);
                x--;
                y++;
            }
            if(turn%2==0){
                for(int j=0;j<v1.size();j++){
                    ans.push_back(v1[j]);
                }
            }
            else{
               for(int j=v1.size()-1;j>=0;j--){
                    ans.push_back(v1[j]);
                } 
            }
            turn++;
        }
        for(int i=1;i<m;i++){
            int x=n-1;
            int y=i;
            vector<int>v1;
            while(x>=0 && y<m && y>=0 && x<n){
                v1.push_back(mat[x][y]);
                y++;
                x--;
            }
            if(turn%2==0){
                for(int j=0;j<v1.size();j++){
                    ans.push_back(v1[j]);
                }
            }
            else{
               for(int j=v1.size()-1;j>=0;j--){
                    ans.push_back(v1[j]);
                } 
            }
            turn++;
        }
        return ans;
    }
};