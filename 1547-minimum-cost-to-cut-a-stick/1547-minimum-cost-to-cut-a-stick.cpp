class Solution {
public:
    map<pair<pair<int,int>,pair<int,int>>,int>dp;
    int fun(vector<int>& cuts,int l,int r,int x,int size){
        if(l>r){
            return 0;
        }
        if(l==r){
            return (size-x);
        }
        if(dp.find({{l,r},{x,size}})!=dp.end()){
            return dp[{{l,r},{x,size}}];
        }
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            int s=fun(cuts,l,i-1,x,cuts[i])+fun(cuts,i+1,r,cuts[i],size);
            ans=min(ans,s);
        }
        return dp[{{l,r},{x,size}}]=ans+(size-x);
    }
    int minCost(int n, vector<int>& cuts) {
        dp.clear();
        sort(cuts.begin(),cuts.end());
        return fun(cuts,0,cuts.size()-1,0,n);
    }
};