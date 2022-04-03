class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int x=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                x=i;
            }
        }
        if(x==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int y=1;
        for(int i=x;i<n;i++){
            if(nums[i]>nums[x]){
                y=i;
            }
        }
        swap(nums[x],nums[y]);
        reverse(nums.begin()+x+1,nums.end());
    }
};
