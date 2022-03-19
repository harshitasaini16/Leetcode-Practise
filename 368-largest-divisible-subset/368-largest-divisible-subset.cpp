class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp;
        for(int i=0;i<n;i++){
            vector<int>v;
            v.push_back(nums[i]);
            dp.push_back(v);
        }
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i].size()<=dp[j].size()){
                    dp[i].clear();
                    dp[i]=dp[j];
                    dp[i].push_back(nums[i]);
                   if(dp[i].size()>mx){
                       mx=dp[i].size();
                   }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<dp[i].size();j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<dp.size();i++){
            if(dp[i].size()==mx){
                return dp[i];
            }
        }
        return {};
    }
};
// 1 2 4 8 49 343