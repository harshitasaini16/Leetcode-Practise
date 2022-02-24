class Solution {
public:
    vector<vector<int>>ans;
    void fun(int i,vector<int>a,int target,vector<int>v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i==a.size()){
            return;
        }
        if(a[i]>target){
            return;
        }
        if(target<0){
            return;
        }
        v.push_back(a[i]);
        fun(i+1,a,target-a[i],v);
        v.pop_back();
        int x=a[i];
        while(i<a.size() && a[i]==x){
            i++;
        }
        fun(i,a,target,v);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        fun(0,candidates,target,v);
        return ans;
    }
};