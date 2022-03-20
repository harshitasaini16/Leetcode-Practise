class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>count(mx+1,0);
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        vector<int>dp(mx+1,0);
        dp[0]=0;
        dp[1]=count[1];
        for(int i=2;i<=mx;i++){
            dp[i]=max(dp[i-1],dp[i-2]+(i*count[i]));
        }
        return dp[mx];
    }
};