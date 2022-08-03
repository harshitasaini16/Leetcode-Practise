class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]-1]==0){
                int x=nums[i];
                int s=0;
                while(m[x]>0){
                    x++;
                    s++;
                }
                ans=max(ans,s);
            }
        }
        return ans;
    }
};