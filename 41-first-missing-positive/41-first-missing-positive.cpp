class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int x=1;
        while(m[x]>0){
            x++;
        }
        return x;
    }
};