class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid==0){
                if(nums[mid]>nums[mid+1]){
                    return mid;
                }
                else{
                    l++;
                }
            }
            else if(mid==n-1){
                if(nums[mid]>nums[mid-1]){
                    return mid;
                }
                else{
                    r--;
                }
            }
            else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                l++;
            }
            else{
                r--;
            }
        }
        return -1;
    }
};