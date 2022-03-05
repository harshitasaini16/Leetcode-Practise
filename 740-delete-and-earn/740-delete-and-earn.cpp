class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<int>dp(10001,0);
        for(int i=0;i<=10000;i++){
            if(i==0){
                dp[i]=0;
            }
            else if(i==1){
                dp[i]=i*m[i];
            }
            else{
                dp[i]=max(dp[i-1],dp[i-2]+(i*m[i]));
            }
        }
        return dp[10000];
    }
};