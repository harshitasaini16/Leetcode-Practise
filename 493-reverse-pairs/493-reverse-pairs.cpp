class Solution {
public:
    int ans;
    void f(int l,int m,int r,vector<int>& nums){
        int x=l;
        int y=m+1;
        while(x<=m && y<=r){
            if((long long)nums[x]>((long long)2*nums[y])){
                ans+=(m-x+1);
                y++;
            }
            else{
                x++;
            }
        }
        sort(nums.begin()+l,nums.begin()+r+1);
    }
    void fun(int l,int r,vector<int>& nums){
        if(l<r){
            int mid=l+(r-l)/2;
            fun(l,mid,nums);
            fun(mid+1,r,nums);
            f(l,mid,r,nums);
        }
    }
    int reversePairs(vector<int>& nums) {
        ans=0;
        fun(0,nums.size()-1,nums);
        return ans;
    }
};