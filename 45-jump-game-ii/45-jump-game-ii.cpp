class Solution {
public:
    int mat[10001];
    int fun(int x,vector<int>&nums,int n){
        if(x==n-1){
            return 0;
        }
        if(x>=n){
            return INT_MAX;
        }
        if(mat[x]!=-1){
            return mat[x];
        }
        int y=INT_MAX-1;
        for(int i=1;i<=nums[x];i++){
            y=min(y,fun(x+i,nums,n));
        }
        return mat[x]=1+y;
    }
    int jump(vector<int>& nums) {
        memset(mat,-1,sizeof(mat));
        return fun(0,nums,nums.size());
    }
};