class Solution {
public:
    vector<vector<int>>ans;
    void fun(int x,vector<int>& can,int tar,vector<int>v){
        if(tar==0){
            ans.push_back(v);
            return;
        }
        if(x>=can.size()){
            return;
        }
        if(can[x]>tar){
            return;
        }
        int i=x;
        while(i<can.size() && can[x]==can[i]){
            i++;
        }
        fun(i,can,tar,v);
        v.push_back(can[x]);
        tar-=can[x];
        fun(x+1,can,tar,v);
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        ans.clear();
        sort(can.begin(),can.end());
        vector<int>v;
        fun(0,can,tar,v);
        return ans;
    }
};