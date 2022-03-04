class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>count(n,1);
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && count[j]>=count[i]){
                    count[i]=count[j]+1;
                    mx=max(mx,count[i]);
                }
            }
        }
        return mx;
    }
};