class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int j=1;
        int n=nums.size();
        while(i<n && j<n){
            if(nums[i]!=nums[i-1] && nums[i]!=nums[j-1]){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j;
    }
};