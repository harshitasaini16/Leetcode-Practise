class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& informTime) {
        map<int,vector<int>>parent;
        for(int i=0;i<man.size();i++){
            parent[man[i]].push_back(i);
        }
        // map<int,int>vis;
        // vis[headID]++;
        queue<pair<int,int>>q;
        q.push({headID,0});
        int mx=INT_MIN;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            mx=max(mx,y);
            q.pop();
            for(int j=0;j<parent[x].size();j++){
                q.push({parent[x][j],y+informTime[x]});
            }
        }
        return mx;
    }
};