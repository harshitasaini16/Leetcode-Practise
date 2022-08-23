class Solution {
public:
    int merge(int l,int m,int r,vector<int>& nums){
        int i=l;
        int j=m+1;
        int ans=0;
        vector<int>v;
        while(i<=m && j<=r){
            if(nums[i]>(long long)2*nums[j]){
                ans+=(m-i)+1;
                v.push_back(nums[j]);
                j++;
            }
            else{
                v.push_back(nums[i]);
                i++;
            }
        }
        while(i<=m){
            v.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            v.push_back(nums[j]);
            j++;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            nums[i+l]=v[i];
        }
        return ans;
    }
    int fun(int l,int r,vector<int>& nums){
        if(l<r){
            int mid=l+(r-l)/2;
            int ans=0;
            ans+=fun(l,mid,nums);
            ans+=fun(mid+1,r,nums);
            ans+=merge(l,mid,r,nums);
            return ans;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        return fun(0,nums.size()-1,nums);
    }
};