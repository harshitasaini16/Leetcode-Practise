class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    void fun(int x,vector<int>&nums){
        if(x==nums.size()){
            s.insert(nums);
            // ans.push_back(nums);
            return;
        }
        for(int i=x;i<nums.size();i++){
            if(i==x || nums[i]!=nums[i-1]){
                swap(nums[x],nums[i]);
                fun(x+1,nums);
                swap(nums[x],nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        fun(0,nums);
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};