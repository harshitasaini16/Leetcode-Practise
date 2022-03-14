class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1){
            return -1;
        }
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int s=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                queue<int>q;
                q.push(i);
                vis[i]=true;
                s++;
                while(!q.empty()){
                   int x=q.front();
                   q.pop();
                   for(auto j:adj[x]){
                       if(vis[j]==false){
                          vis[j]=true;
                          q.push(j);
                        }
                    }
                }
            }
        }
        return s-1;
    }
};