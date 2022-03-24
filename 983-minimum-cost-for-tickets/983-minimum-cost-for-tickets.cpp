class Solution {
public:
    map<int,int>dp;
    int fun(int x,map<int,int>&m,vector<int>&costs){
        if(x>365){
            return 0;
        }
        if(dp.find(x)!=dp.end()){
            return dp[x];
        }
        if(m[x]==0){
            return dp[x]=fun(x+1,m,costs);
        }
        int a=costs[0]+fun(x+1,m,costs);
        int b=costs[1]+fun(x+7,m,costs);
        int c=costs[2]+fun(x+30,m,costs);
        return dp[x]=min({a,b,c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int,int>m;
        dp.clear();
        for(int i=0;i<days.size();i++){
            m[days[i]]++;
        }
        return fun(1,m,costs);
    }
};