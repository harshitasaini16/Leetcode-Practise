class Solution {
public:
    double fun(vector<int>& nums1,int n, vector<int>& nums2,int m){
        if(m<n){
            return fun(nums2,m,nums1,n);
        }
        int l=0,r=n;
        int tot=(n+m+1)/2;
        while(l<=r){
            int mid=l+(r-l)/2;
            int cut1=mid;
            int cut2=tot-cut1;
            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int r1=(cut1==n)?INT_MAX:nums1[cut1];
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r2=(cut2==m)?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }
                else{
                    return (double)max(l1,l2);
                }
            }
            if(l1>r2){
                r=cut1-1;
            }
            else{
                l=cut1+1;
            }
        }
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        return fun(nums1,n,nums2,m);
    }
};