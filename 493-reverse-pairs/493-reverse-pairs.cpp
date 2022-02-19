
#define ll long long
class Solution {
public:
    
    int ans;
    void merge(int l,int m,int r,vector<int>& nums){
        int i=l,j=m+1 ;
        
        while(i <= m && j <= r)
        {
            if((ll)nums[i] > (ll)2*nums[j])    // used ll to avoid overflow error
            {
                ans += m- i + 1  ;
                j++ ;
            }else 
            {
                i++ ;
            }
        }
        
        sort(nums.begin()+l,nums.begin() + r + 1) ;

    }
    void fun(int l,int r,vector<int>& nums){
        int s=0;
        if(l<r){
            int mid=l+(r-l)/2;
            fun(l,mid,nums);
            fun(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }
    int reversePairs(vector<int>& nums) {
        ans=0;
        fun(0,nums.size()-1,nums);
        return ans;
    }
};