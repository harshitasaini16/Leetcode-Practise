class Solution {
public:
    vector<vector<int>>ans;
    void fun(int x,vector<int>nums){
        if(x==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=x;i<nums.size();i++){
            swap(nums[i],nums[x]);
            fun(x+1,nums);
            swap(nums[i],nums[x]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        fun(0,nums);
        return ans;
    }
};