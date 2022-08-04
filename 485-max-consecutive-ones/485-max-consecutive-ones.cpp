class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int s=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                s++;
            }
            else{
                s=0;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};