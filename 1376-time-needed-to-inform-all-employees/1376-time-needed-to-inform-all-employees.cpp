class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& inform) {
        map<int,vector<int>>parent;
        int p=0;
        for(int i=0;i<man.size();i++){
            parent[man[i]].push_back(i);
            if(man[i]==-1){
                p=i;
            }
        }
        queue<pair<int,int>>q;
        q.push({p,0});
        int ans=INT_MIN;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            ans=max(ans,y);
            q.pop();
            for(int i=0;i<parent[x].size();i++){
                q.push({parent[x][i],y+inform[x]});
            }
        }
        return ans;
    }
};