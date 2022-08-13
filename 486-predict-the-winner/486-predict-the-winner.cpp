class Solution {
public:
    int fun(int l,int r,vector<int>& nums){
        if(l>r){
            return 0;
        }
        if(l==r){
            return nums[l];
        }
        return max(nums[l]+min(fun(l+2,r,nums),fun(l+1,r-1,nums)), nums[r]+min(fun(l+1,r-1,nums),fun(l,r-2,nums)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int s1=fun(0,nums.size()-1,nums);
        int s2=sum-s1;
        return s1>=s2;
    }
};