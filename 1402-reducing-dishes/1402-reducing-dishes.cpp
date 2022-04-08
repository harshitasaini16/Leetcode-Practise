class Solution {
public:
    int dp[1000][1000];
    int fun(int x,vector<int>&sat,int num){
        if(x==sat.size()){
            return 0;
        }
        if(dp[x][num]!=-1){
            return dp[x][num];
        }
        int temp1=fun(x+1,sat,num);
        int temp2=sat[x]*num+fun(x+1,sat,num+1);
        return dp[x][num]=max(temp1,temp2);
    }
    int maxSatisfaction(vector<int>& sat) {
        memset(dp,-1,sizeof(dp));
        sort(sat.begin(),sat.end());
        return fun(0,sat,1);
    }
};