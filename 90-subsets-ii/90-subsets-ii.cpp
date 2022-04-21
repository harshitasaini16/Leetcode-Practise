class Solution {
public:
    vector<vector<int>>ans;
    void fun(int x,vector<int>& nums,vector<int>v){
        if(x==nums.size()){
            ans.push_back(v);
            return;
        }
        int j=x;
        while(j<nums.size() && nums[x]==nums[j]){
            j++;
        }
        fun(j,nums,v);
        v.push_back(nums[x]);
        fun(x+1,nums,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        fun(0,nums,v);
        return ans;
    }
};