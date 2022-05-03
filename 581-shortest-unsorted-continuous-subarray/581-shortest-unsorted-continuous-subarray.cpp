class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        int begin=-1;
        int end=-2;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            if(nums[i]<mx){
                end=i;
            }
        }
        int mn=nums[n-1];
        int i=n-1;
        while(i>=0){
            mn=min(mn,nums[i]);
            if(nums[i]>mn){
                begin=i;
            }
            i--;
        }
        return end-begin+1;
    }
};