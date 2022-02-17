class Solution {
public:
    vector<vector<int>>ans;
    void fun(int i,vector<int>& can, int target,vector<int>v,int s){
        if(s==target){
            ans.push_back(v);
            return;
        }
        if(s>target){
            return;
        }
        if(i==can.size()){
            return;
        }
        fun(i+1,can,target,v,s);
        v.push_back(can[i]);
        fun(i,can,target,v,s+can[i]);
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        ans.clear();
        vector<int>v;
        fun(0,can,target,v,0);
        return ans;
    }
};