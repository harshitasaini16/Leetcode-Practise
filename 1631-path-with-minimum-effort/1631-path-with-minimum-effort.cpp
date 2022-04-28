class Solution {
public:
    bool fun(int i,int j,int c,int n,int m,vector<vector<int>>&arr,vector<vector<bool>>&vis){
        if(i==n-1 and j==m-1){
            return true;
        }
        vis[i][j]=1;
        bool ans=false;
        if(i<n-1 and vis[i+1][j]==0 and abs(arr[i][j]-arr[i+1][j])<=c){
            ans=ans or fun(i+1,j,c,n,m,arr,vis);
        }
        if(j>0 and vis[i][j-1]==0 and abs(arr[i][j]-arr[i][j-1])<=c){
            ans=ans or fun(i,j-1,c,n,m,arr,vis);
        }
        if(j<m-1 and vis[i][j+1]==0 and abs(arr[i][j]-arr[i][j+1])<=c){
            ans=ans or fun(i,j+1,c,n,m,arr,vis);
        }
        if(i>0 and vis[i-1][j]==0 and abs(arr[i][j]-arr[i-1][j])<=c){
            ans=ans or fun(i-1,j,c,n,m,arr,vis);
        }
        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
        int ans=INT_MAX;
        int s=0,e=INT_MAX;
        while(s<=e){
            int m=(s+e)/2;
            int n=arr.size();
            int mm=arr[0].size();
            vector<vector<bool>>vis(n,vector<bool>(mm,false));
            if(fun(0,0,m,arr.size(),arr[0].size(),arr,vis)){
                ans=min(ans,m);
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};