class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            ans=max(s,ans);
            if(s<0){
                s=0;
            }
        }
        return ans;
    }
};