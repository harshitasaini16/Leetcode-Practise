class Solution {
public:
    vector<vector<int>>ans;
    void fun(int x,vector<int>& nums,vector<int>v){
        if(x==nums.size()){
            ans.push_back(v);
            return;
        }
        fun(x+1,nums,v);
        v.push_back(nums[x]);
        fun(x+1,nums,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        fun(0,nums,v);
        return ans;
    }
};