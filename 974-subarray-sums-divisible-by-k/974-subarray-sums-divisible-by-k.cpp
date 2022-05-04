class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        map<int,int>m;
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s%k==0){
                ans++;
            }
            int x=(s%k+k)%k;
            ans+=m[x];
            m[x]++;
        }
        return ans;
    }
};