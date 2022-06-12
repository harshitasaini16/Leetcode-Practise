class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            nums[x-1]=-nums[x-1];
            if(nums[x-1]>0){
                ans.push_back(x);
            }
        }
        return ans;
    }
};