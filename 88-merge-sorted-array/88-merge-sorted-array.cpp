class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int k=n+m;
        while(n>0 && m>0){
            if(nums1[n-1]>=nums2[m-1]){
                nums1[k-1]=nums1[n-1];
                n--;
                k--;
            }
            else{
                nums1[k-1]=nums2[m-1];
                k--;
                m--;
            }
        }
        while(m>0){
            nums1[k-1]=nums2[m-1];
            k--;
            m--;
        }
    }
};