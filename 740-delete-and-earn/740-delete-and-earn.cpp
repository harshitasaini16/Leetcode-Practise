class Solution {
public:
    unordered_map<int,int>vis;
    int fun(vector<pair<int,int>>&v,int i,int n){
        if(i>=n){
            return 0;
        }
        if(vis[i]!=0){
            return vis[i];
        }
        if(i==n-1){
            return v[i].first*v[i].second;
        }
        if(v[i].first+1!=v[i+1].first){
            return vis[i]=v[i].first*v[i].second+fun(v,i+1,n);
        }
        int x=v[i].first*v[i].second+fun(v,i+2,n);
        int y=fun(v,i+1,n);
        return vis[i]=max(x,y);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int,int>>v;
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        for(auto [k,vv]:m){
            v.push_back({k,vv});
        }
        int n=v.size();
        return fun(v,0,n);
    }
};