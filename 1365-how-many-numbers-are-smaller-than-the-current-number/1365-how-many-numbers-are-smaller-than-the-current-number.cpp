class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=1;i<=101;i++){
            m[i]+=m[i-1];
        }
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            v.push_back(m[nums[i]-1]);
        }
        return v;
    }
};