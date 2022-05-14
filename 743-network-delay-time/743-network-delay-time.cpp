class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        while(!q.empty()){
            int w=q.top().first;
            int i=q.top().second;
            q.pop();
            for(int j=0;j<adj[i].size();j++){
               if(dis[adj[i][j].first]>adj[i][j].second+dis[i]){
                   dis[adj[i][j].first]=adj[i][j].second+dis[i];
                   q.push({dis[adj[i][j].first],adj[i][j].first});
               }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            // cout<<dis[i]<<' ';
            mx=max(mx,dis[i]);
        }
        if(mx==INT_MAX){
            return -1;
        }
        return mx;
    }
};