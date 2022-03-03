class Solution {
public:
    vector<vector<int>>ans;
    void fun(int x,vector<int>nums){
        if(x==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=x;i<nums.size();i++){
            swap(nums[x],nums[i]);
            fun(x+1,nums);
            swap(nums[x],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        fun(0,nums);
        return ans;
    }
};