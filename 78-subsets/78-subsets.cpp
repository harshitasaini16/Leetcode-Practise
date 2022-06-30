class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>& nums,int x,vector<int>v){
        if(x==nums.size()){
            ans.push_back(v);
            return;
        }
        fun(nums,x+1,v);
        v.push_back(nums[x]);
        fun(nums,x+1,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        fun(nums,0,v);
        return ans;
    }
};