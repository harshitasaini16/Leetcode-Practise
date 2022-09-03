class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        int ans1=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans1=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        l=0;
        r=n-1;
        int ans2=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans2=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(ans2==-1){
            return {-1,-1};
        }
        return {ans1,ans2};
    }
};