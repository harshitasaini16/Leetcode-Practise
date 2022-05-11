class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int s1=0;
        int av=nums[nums.size()/2];
        for(int i=0;i<nums.size();i++){
            s1+=abs(av-nums[i]);
        }
        return s1;
    }
};