class Solution {
public:
    map<int,int>dp;
    int fun(vector<int>& arr, int d,int x){   
        int ans=0;
        if(dp.find(x)!=dp.end()){
            return dp[x];
        }
        for(int i=x-1;i>=(x-d) and i>=0;i--){
            if( arr[i]>=arr[x]){
                break;
            }
            else{
                ans=max(ans,fun(arr,d,i));
            }
        }
        for(int i=x+1;i<=(x+d) and i<arr.size();i++){
            if( arr[i]>=arr[x]){
                break;
            }
            else{
                ans=max(ans,fun(arr,d,i));
            }
           
        }
        return dp[x]=ans+1;
    }
    int maxJumps(vector<int>& arr, int d) {
        dp.clear();
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,fun(arr,d,i));
        }
        return ans;
    }
};