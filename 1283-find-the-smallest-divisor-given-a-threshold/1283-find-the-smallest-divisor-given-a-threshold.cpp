class Solution {
public:
    int fun(vector<int>& nums, int threshold,int x){
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i]/x;
            if(nums[i]%x!=0){
                s++;
            }
        }
        if(s<=threshold){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(fun(nums,threshold,mid)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};