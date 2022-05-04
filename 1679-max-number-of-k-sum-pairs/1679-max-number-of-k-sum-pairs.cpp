class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(m[k-x]>0){
                ans++;
                m[k-x]--;
            }
            else{
                m[nums[i]]++;
            }
        }
        return ans;
    }
};