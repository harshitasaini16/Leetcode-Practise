class Solution {
public:
    int fun(int x,vector<int>vis,int n){
        if(x>n){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0 && (i%x==0 || x%i==0)){
                vis[i]=1;
                ans+=fun(x+1,vis,n);
                vis[i]=0;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int>vis(n+1,0);
        return fun(1,vis,n);
    }
};