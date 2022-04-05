class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        int z=0;
        for(int i=0;i<s;i++){
            if(nums[i]==0){
                z++;
            }
        }
        int ans=z;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                z--;
            }
            if(nums[(i+s)%n]==0){
                z++;
            }
            ans=min(ans,z);
        }
        return ans;
    }
};