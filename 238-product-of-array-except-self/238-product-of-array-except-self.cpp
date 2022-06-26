class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int x=1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(x);
            x*=nums[i];
        }
        x=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=x;
            x*=nums[i];
        }
        return ans;
    }
};