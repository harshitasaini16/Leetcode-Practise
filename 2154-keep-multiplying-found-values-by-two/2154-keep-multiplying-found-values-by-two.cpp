class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        while(m.find(o)!=m.end()){
            o*=2;
        }
        return o;
    }
};