class Solution {
public:
    int fun(int l,int r,vector<int>nums,int n){
        if(l<=r){
            if(nums[l]<nums[r]){
                return nums[l];
            }
            int mid=l+(r-l)/2;
            if(mid==0){
                if(nums[mid]<nums[n-1]){
                    return nums[mid];
                }
                else{
                    return fun(mid+1,r,nums,n);
                }
            }
            else if(mid==n-1){
                if(nums[mid]<nums[0] && nums[mid]<nums[mid-1]){
                    return nums[mid];
                }
                else{
                    return fun(l,mid-1,nums,n);
                }
            }
            else{
                if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){
                    return nums[mid];
                }
                if(nums[0]<nums[mid]){
                    return fun(mid+1,r,nums,n);
                }
                else{
                    return fun(l,mid-1,nums,n);
                }
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        return fun(0,nums.size()-1,nums,nums.size());
    }
};