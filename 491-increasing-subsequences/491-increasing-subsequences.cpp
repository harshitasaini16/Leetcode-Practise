class Solution {
public:
    set<vector<int>>ans;
    void fun(int x,vector<int>& nums,vector<int>v){
        if(x>=nums.size()){
            if(v.size()>=2){
                ans.insert(v);
                return;
            }
            return;
        }
        int i=x;
        while(i<nums.size() && nums[i]==nums[x]){
            i++;
        }
        fun(i,nums,v);
        if(v.size()==0 || v[v.size()-1]<=nums[x]){
            v.push_back(nums[x]);
            fun(x+1,nums,v);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        vector<int>v;
        fun(0,nums,v);
        vector<vector<int>>ss;
        for(auto i:ans){
            ss.push_back(i);
        }
        return ss;
    }
};