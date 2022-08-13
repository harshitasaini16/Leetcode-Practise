class Solution {
public:
    int f(int l,int m,int r,vector<int>& nums){
        int x=l;
        int y=m+1;
        int s=0;
        while(x<=m && y<=r){
            if((long long)nums[x]>((long long)2*nums[y])){
                s+=(m-x+1);
                y++;
            }
            else{
                x++;
            }
        }
        sort(nums.begin()+l,nums.begin()+r+1);
        return s;
    }
    int fun(int l,int r,vector<int>& nums){
        if(l<r){
            int mid=l+(r-l)/2;
            int x1=fun(l,mid,nums);
            int x2=fun(mid+1,r,nums);
            int x3=f(l,mid,r,nums);
            return x1+x2+x3;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        return fun(0,nums.size()-1,nums);
    }
};