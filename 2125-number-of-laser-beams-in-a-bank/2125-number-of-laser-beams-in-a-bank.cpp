class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int x=0;
        for(int i=0;i<bank.size();i++){
            int y=0;
            for(int j=0;j<bank[0].size();j++){
                y+=bank[i][j]-'0';
            }
            if(y>0){
                ans+=(x*y);
                x=y;
            }
        }
        return ans;
    }
};