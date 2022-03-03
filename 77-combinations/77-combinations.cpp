class Solution {
public:
    vector<vector<int>>ans;
    void fun(int x,int n,vector<int>v,int k){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=x;i<=n;i++){
            v.push_back(i);
            fun(i+1,n,v,k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int>v;
        fun(1,n,v,k);
        return ans;
    }
};