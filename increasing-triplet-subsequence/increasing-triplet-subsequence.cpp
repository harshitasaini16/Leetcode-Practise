class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX;
        int second=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=first){
                first=nums[i];
            }
            else if(nums[i]<=second){
                second=nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};