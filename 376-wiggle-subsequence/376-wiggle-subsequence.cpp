class Solution {
public:
    int dp[1001][5];
    int fun(int i,vector<int>& nums,int d){
        if(i>=nums.size()-1){
            return 1;
        }
        if(dp[i][d]!=-1){
            return dp[i][d];
        }
        if(d==2){
            int s1=fun(i+1,nums,d);
            int s2=0;
            if(nums[i]<nums[i+1]){
                s2=1+fun(i+1,nums,0);
            }
            else if(nums[i]==nums[i+1]){
                s2=fun(i+1,nums,d);
            }
            else if(nums[i]>nums[i+1]){
                s2=1+fun(i+1,nums,1);
            }
            return dp[i][d]=max(s1,s2);
        }
        else if(d==1){
            int s1=fun(i+1,nums,d);
            int s2=0;
            if(nums[i]<nums[i+1]){
                s2=1+fun(i+1,nums,0);
            }
            else if(nums[i]==nums[i+1]){
                s2=fun(i+1,nums,d);
            }
            else if(nums[i]>nums[i+1]){
                s2=fun(i+1,nums,1);
            }
            return dp[i][d]=max(s1,s2);
        }
        else if(d==0){
            int s1=fun(i+1,nums,d);
            int s2=0;
            if(nums[i]<nums[i+1]){
                s2=fun(i+1,nums,0);
            }
            else if(nums[i]==nums[i+1]){
                s2=fun(i+1,nums,d);
            }
            else if(nums[i]>nums[i+1]){
                s2=1+fun(i+1,nums,1);
            }
            return dp[i][d]=max(s1,s2);
        }
        return 0;
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,nums,2);
    }
};