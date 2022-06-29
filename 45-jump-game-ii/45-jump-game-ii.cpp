class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int mx=nums[0];
        if(n==1){
            return 0;
        }
        int s=nums[0];
        for(int i=1;i<n;i++){
            if(mx>=n-1){
                return ans;
            }
            if(i<=mx){
                s=max(s,i+nums[i]);
            }
            else{
                ans++;
                mx=s;
                s=max(s,i+nums[i]);
            }
        }
        return ans;
    }
};