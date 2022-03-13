class Solution {
public:
    vector<vector<int>>ans;
    void fun(int x,map<int,bool>vis,vector<vector<int>>& graph,vector<int>v){
        if(x==graph.size()-1){
            v.push_back(x);
            ans.push_back(v);
            return;
        }
        v.push_back(x);
        vis[x]=true;
        for(auto i:graph[x]){
            if(vis[i]==false){
                fun(i,vis,graph,v);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>v;
        map<int,bool>vis;
        fun(0,vis,graph,v);
        return ans;
    }
};