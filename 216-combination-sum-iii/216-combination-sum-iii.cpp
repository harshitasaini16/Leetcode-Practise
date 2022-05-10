class Solution {
public:
    vector<vector<int>>ans;
    void fun(int s,int x,int k,int n,vector<int>v){
        if(s==n){
            if(v.size()==k){
                ans.push_back(v);
            }
            return;
        }
        if(s>n || x>=10){
            return;
        }
        fun(s,x+1,k,n,v);
        s+=x;
        v.push_back(x);
        fun(s,x+1,k,n,v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        fun(0,1,k,n,v);
        return ans;
    }
};