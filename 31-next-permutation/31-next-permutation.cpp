class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                x=i;
            }
        }
        if(x==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int y;
        for(int j=x+1;j<n;j++){
            if(nums[j]>nums[x]){
                y=j;
            }
        }
        swap(nums[x],nums[y]);
        sort(nums.begin()+x+1,nums.end());
    }
};