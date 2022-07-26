class Solution {
public:
    int smallest(vector<int>& a,int l,int r,int n){
        if(l<=r){
            if(a[l]<=a[r]){
                return l;
            }
            int mid=l+(r-l)/2;
            if(mid==0 && a[mid]<a[mid+1]){
                return mid;
            }
            else if(mid==0 && a[mid]>a[mid+1]){
                return smallest(a,mid+1,r,n);
            }
            else if(mid==n-1 && a[mid]<a[mid-1]){
                return mid;
            }
            else if(mid==n-1 && a[mid]>a[mid-1]){
                return smallest(a,mid+1,r,n);
            }
            if(mid!=0 && mid!=n-1 && a[mid]<a[mid-1] && a[mid]<a[mid+1]){
                return mid;
            }
            if(mid!=0 && mid!=n-1 && a[0]<a[mid]){
                return smallest(a,mid+1,r,n);
            }
            if(mid!=0 && mid!=n-1 && a[mid]<a[r]){
                return smallest(a,0,mid,n);
            }
        }
        return -1;
    }
    int binary(int l,int r,vector<int>&a,int target){
        if(l<=r){
            int mid=l+(r-l)/2;
            if(a[mid]==target){
                return mid;
            }
            else if(a[mid]<target){
                return binary(mid+1,r,a,target);
            }
            else{
                return binary(l,mid-1,a,target);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==target){
                return 0;
            }
            else{
                return -1;
            }
        }
        int i = smallest(nums,0,nums.size()-1,nums.size());
        if(binary(0,i-1,nums,target)!=-1){
            return binary(0,i-1,nums,target);
        }
        else if(binary(i,n-1,nums,target)!=-1){
            return binary(i,n-1,nums,target);
        }
        return -1;
    }
};