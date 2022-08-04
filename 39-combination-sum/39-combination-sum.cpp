class Solution {
public:
    vector<vector<int>>ans;
    void fun(int x,vector<int>& can,int target,vector<int>&v,int s){
        if(s==target){
            ans.push_back(v);
            return;
        }
        if(x>can.size()){
            return;
        }
        if(x==can.size()){
            if(s==target){
                ans.push_back(v);
            }
            return;
        }
        if(s+can[x]<=target){
            fun(x+1,can,target,v,s);
            s+=can[x];
            v.push_back(can[x]);
            fun(x,can,target,v,s);
            v.pop_back();
        }
        else{
            fun(x+1,can,target,v,s);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<int>v;
        fun(0,can,target,v,0);
        return ans;
    }
};