class Solution {
public:
    int fun(vector<int>& nums,int x){
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=abs(nums[i]-x);
        }
        return s;
    }
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%2!=0){
            return fun(nums,nums[n/2]);
        }
        return min(fun(nums,nums[n/2-1]),fun(nums,nums[n/2]));
    }
};