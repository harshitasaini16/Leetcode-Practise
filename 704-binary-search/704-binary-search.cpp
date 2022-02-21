class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int ans=-1;
        int r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                ans=m;
                break;
            }
            else if(nums[m]>target){
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
        }
        return ans;
    }
};