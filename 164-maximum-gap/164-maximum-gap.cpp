class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }
        int mn=nums[0];
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        int interval=(mx-mn)/(n-1);
        if((mx-mn)%(n-1)!=0){
            interval++;
        }
        if(interval==0){
            return 0;
        }
        vector<int>minn(n,INT_MAX);
        vector<int>maxx(n,INT_MIN);
        for(int i=0;i<n;i++){
            int x=(nums[i]-mn)/interval;
            minn[x]=min(minn[x],nums[i]);
            maxx[x]=max(maxx[x],nums[i]);
        }
        vector<int>minn2,maxx2;
        for(int i=0;i<n;i++){
            if(minn[i]!=INT_MAX && maxx[i]!=INT_MIN){
                minn2.push_back(minn[i]);
                maxx2.push_back(maxx[i]);
            }
        }
        int ans=0;
        for(int i=1;i<minn2.size();i++){
            ans=max(ans,minn2[i]-maxx2[i-1]);
        }
        return ans;
    }
};