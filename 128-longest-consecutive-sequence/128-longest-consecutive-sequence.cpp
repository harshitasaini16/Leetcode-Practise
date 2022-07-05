class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int mx=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int s=0;
            if(m[x-1]==0){
                while(m[x]>0){
                    x++;
                    s++;
                }
                mx=max(mx,s);
            }
        }
        return mx;
    }
};