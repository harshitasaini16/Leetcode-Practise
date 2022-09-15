class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(dp[dp.size()-1]<nums[i]){
                dp.push_back(nums[i]);
            }
            else{
                int x=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[x]=nums[i];
            }
        }
        return dp.size();
    }
};