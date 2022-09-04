class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid==0){
                if(nums[mid]>nums[mid+1]){
                    return mid;
                }
                else{
                    l=mid+1;
                }
            }
            else if(mid==n-1){
                if(nums[mid-1]<nums[mid]){
                    return mid;
                }
                else{
                    r=mid-1;
                }
            }
            else if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1]>nums[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};