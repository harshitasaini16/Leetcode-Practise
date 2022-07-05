class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        double s=0;
        for(int i=0;i<k;i++){
            s+=nums[i];
        }
        ans=(double)s/(double)k;
        for(int i=k;i<nums.size();i++){
            s+=nums[i];
            s-=nums[i-k];
            ans=max(ans,(double)s/(double)k);
        }
        return ans;
    }
};