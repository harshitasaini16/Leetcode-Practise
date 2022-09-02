class Solution {
public:
    double fun(vector<int>& nums1, vector<int>& nums2){
        if(nums2.size()<nums1.size()){
            return fun(nums2,nums1);
        }
        int n=nums1.size();
        int m=nums2.size();
        int k=(n+m+1)/2;
        int l=0;
        int r=n;
        while(l<=r){
            int cut1=l+(r-l)/2;
            int cut2=k-cut1;
            int mn1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int mx1=(cut1==n)?INT_MAX:nums1[cut1];
            int mn2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int mx2=(cut2==m)?INT_MAX:nums2[cut2];
            if(mn1<=mx2 && mn2<=mx1){
                if((n+m)%2==0){
                    return (double)(max(mn1,mn2)+min(mx1,mx2))/(double)2;
                }
                else{
                    return max(mn1,mn2);
                }
            }
            else if(mn1>mx2){
                r=cut1-1;
            }
            else{
                l=cut1+1;
            }
        }
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return fun(nums1,nums2);
    }
};