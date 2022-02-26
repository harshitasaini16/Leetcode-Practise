class Solution {
public:
    int fun(vector<vector<int>>& graph){
        int n=(int)graph.size();
        int all=(1<<n)-1;
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>vis;
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }
        while(!q.empty()){
            auto node =q.front();
            q.pop();
            int val=node.first;
            int dist=node.second.first;
            int mask=node.second.second;
            for(auto temp:graph[val]){
                int newmask=(mask | (1<<temp));
                if(newmask==all){
                    return dist+1;
                }
                else if(vis.count({temp,newmask})){
                    continue;
                }
                vis.insert({temp,newmask});
                q.push({temp,{dist+1,newmask}});
            }
        }
        return 0;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
       if(graph.size()==0){
           return 0;
       }
        return fun(graph);
    }
};