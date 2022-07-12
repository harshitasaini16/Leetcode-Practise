class Solution {
public:
    bool fun(vector<int>&arr,int i,int fin,int sum,int rem,vector<bool>&vis){
        if(rem==1){
            return true;
        }
        if(i>=arr.size()){
            return false;
        }
        if(sum==fin){
            return fun(arr,0,fin,0,rem-1,vis);
        }
        for(int j=i;j<arr.size();j++){
            if(vis[j]==true or sum+arr[j]>fin){
                continue;
            }
            vis[j]=true;
            if(fun(arr,j+1,fin,sum+arr[j],rem,vis)==true){
                return true;
            }
            vis[j]=false;
        }
        return false;
    }
    bool makesquare(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(auto x:arr){
            sum+=x;
        }
        if(sum%4!=0  or n<4){
            return false;
        }
        vector<bool>vis(n,false);
        return fun(arr,0,sum/4,0,4,vis);
    }
};