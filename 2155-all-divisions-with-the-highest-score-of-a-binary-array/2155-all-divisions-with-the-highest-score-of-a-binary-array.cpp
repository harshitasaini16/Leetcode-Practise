class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        int left[n+1];
        int c0=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c0++;
            }
        }
        left[n]=c0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                c0--;
            }
            left[i]=c0;
        }
        left[0]=0;
        int right[n+1];
        int c1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                c1++;
            }
        }
        right[0]=c1;
        for(int i=1;i<=n;i++){
            if(nums[i-1]==1){
                c1--;
            }
            right[i]=c1;
        }
        int mx=0;
        for(int i=0;i<=n;i++){
            mx=max(mx,left[i]+right[i]);
        }
        vector<int>ans;
        for(int i=0;i<=n;i++){
            if(left[i]+right[i]==mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
};