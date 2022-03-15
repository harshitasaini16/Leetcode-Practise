class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        int n=arr.size();
        map<int,int>vis;
        vis[start]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(arr[x]==0){
                return true;
            }
            int yi=x-arr[x];
            int yj=x+arr[x];
            if(yi>=0 && vis[yi]==0){
                vis[yi]++;
                q.push(yi);
            }
            if(yj<n && vis[yj]==0){
                q.push(yj);
                vis[yj]++;
            }
        }
        return false;
    }
};