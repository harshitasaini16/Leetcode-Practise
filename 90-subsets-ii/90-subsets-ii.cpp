class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&nums,int i,vector<int>v){
        ans.push_back(v);
        for(int j=i;j<nums.size();j++){
            if(i==j or nums[j]!=nums[j-1]){
                v.push_back(nums[j]);
                fun(nums,j+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int>v;
        sort(nums.begin(),nums.end());
        fun(nums,0,v);
        return ans;
    }
};