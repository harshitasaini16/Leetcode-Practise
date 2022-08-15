class Solution {
public:
    int dp[101][101];
    map<char,vector<int>>m;
    int fun(int x,int y,string ring, string key){
        if(y>=key.size()){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int ans=INT_MAX;
        for(int i=0;i<m[key[y]].size();i++){
            int a=m[key[y]][i];
            int b=x;
            int dis1=abs(a-b);
            int dis2=ring.size()-dis1;
            int temp=min(dis1,dis2)+fun(a,y+1,ring,key);
            ans=min({ans,temp});
        }
        return dp[x][y]=ans+1;
    }
    int findRotateSteps(string ring, string key) {
        m.clear();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<ring.size();i++){
            m[ring[i]].push_back(i);
        }
        return fun(0,0,ring,key);
    }
};