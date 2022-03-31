class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>&dis) {
        vector<int> graph[n+1];
        for(int i=0;i<dis.size();i++){
            graph[dis[i][0]].push_back(dis[i][1]);
            graph[dis[i][1]].push_back(dis[i][0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                queue<int>q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(auto j:graph[x]){
                        if(color[j]==-1){
                            color[j]=!color[x];
                            q.push(j);
                        }
                        else if(color[j]==color[x]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};