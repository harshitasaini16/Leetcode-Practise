class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>m;
        int ans=0;
        int s=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(s%k==0){
                ans++;
            }
            int x=(s%k+k)%k;
            if(m[x]>0){
                ans+=m[x];
            }
            m[x]++;
        }
        return ans;
    }
};