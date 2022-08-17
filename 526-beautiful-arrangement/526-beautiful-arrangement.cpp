class Solution {
public:
    int fun(int x,int n,vector<int>&vis){
        if(x>n){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0 && (x%i==0 || (i%x==0))){
                vis[i]++;
                ans+=fun(x+1,n,vis);
                vis[i]=0;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int>vis(n+1,0);
        return fun(1,n,vis);
    }
};