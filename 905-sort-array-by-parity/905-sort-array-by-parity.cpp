class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(i<n && j<n){
            if(nums[i]%2==0){
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
        return nums;
    }
};