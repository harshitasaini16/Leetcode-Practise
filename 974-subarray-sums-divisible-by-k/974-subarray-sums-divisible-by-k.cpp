class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int s=0;
        map<int,int>m;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(s%k==0){
                ans++;
            }
            ans+=m[(((s%k)+k)%k)];
            m[(((s%k)+k)%k)]++;
        }
        return ans;
    }
};