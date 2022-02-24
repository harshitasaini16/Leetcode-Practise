class Solution {
public:
    set<vector<int>>ans;
    void fun(int i,vector<int>& nums,vector<int>v){
        if(i==nums.size()){
            ans.insert(v);
            return;
        }
        fun(i+1,nums,v);
        v.push_back(nums[i]);
        fun(i+1,nums,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ans.clear();
        vector<int>v;
        fun(0,nums,v);
        vector<vector<int>>s;
        for(auto i:ans){
            s.push_back(i);
        }
        return s;
    }
};