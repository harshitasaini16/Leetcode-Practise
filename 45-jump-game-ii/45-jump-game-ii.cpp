class Solution {
public:
    int jump(vector<int>& nums) {
        int x=1;
        int n=nums.size();
        vector<int>ans(n,INT_MAX);
        ans[0]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i){
                    ans[i]=min(ans[i],ans[j]+1);
                }
            }
        }
        return ans[n-1];
    }
};