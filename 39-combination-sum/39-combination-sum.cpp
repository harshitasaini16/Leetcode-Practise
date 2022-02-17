class Solution {
public:
    void fun(vector<vector<int>>&ans,vector<int>a,vector<int>arr,int sum,int i){
        if(sum==0){
            ans.push_back(a);
            return;
        }
        if(i==arr.size()){
            return;
        }
        fun(ans,a,arr,sum,i+1);
        if(arr[i]<=sum){
            a.push_back(arr[i]);
            fun(ans,a,arr,sum-arr[i],i);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>a;
        fun(ans,a,candidates,target,0);
        return ans;
    }
};