class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=-1;
        int y=-1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                x=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
        }
        l=0;
        r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                y=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
        }
        return {x,y};
    }
};