class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int i=0;
        int j=n-1;
        while(x<=j){
            if(nums[x]==0){
                swap(nums[x],nums[i]);
                x++;
                i++;
            }
            else if(nums[x]==1){
                x++;
            }
            else if(nums[x]==2){
                swap(nums[x],nums[j]);
                j--;
            }
        }
    }
};