class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>m;
        int ans=0;
        int s=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            s=max(s,m[nums[i]]);
            sum+=nums[i];
            ans=max(ans,sum-s);
            m[nums[i]]=sum;
        }
        return ans;
    }
};