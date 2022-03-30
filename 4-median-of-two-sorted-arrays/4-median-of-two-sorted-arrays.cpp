class Solution {
public:
    double fun(vector<int>& nums1,int n,vector<int>& nums2,int m){
        if(m<n){
            return fun(nums2,m,nums1,n);
        }
        int l=0;
        int r=n;
        int mid=(n+m+1)/2;
        while(l<=r){
            int cut1=l+(r-l)/2;
            int cut2=mid-cut1;
            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r1=(cut1==n)?INT_MAX:nums1[cut1];
            int r2=(cut2==m)?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }
                else{
                    return (double)(max(l1,l2));
                }
            }
            else if(l1>r2){
                r=cut1-1;
            }
            else{
                l=cut1+1;
            }
        }
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return fun(nums1,nums1.size(),nums2,nums2.size());
    }
};