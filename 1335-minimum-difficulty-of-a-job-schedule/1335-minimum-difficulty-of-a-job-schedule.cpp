class Solution {
public:
    int dp[301][11];
    int fun(int i,vector<int>&arr,int d,int n){
        if(i==n and d==0){
            return 0;
        }
        if(i==n or d==0){
            return INT_MAX;
        }
        if(dp[i][d]!=-1){
            return dp[i][d];
        }
        int ans=0;
        int mx=INT_MAX;
        for(int j=i;j<n;j++){
            ans=max(ans,arr[j]);
            int a1=fun(j+1,arr,d-1,n);
            if(a1!=INT_MAX){
                mx=min(mx,a1+ans);
            }
        }
        return dp[i][d]=mx;
    }
    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        if(n<d){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return fun(0,arr,d,n);
    }
};