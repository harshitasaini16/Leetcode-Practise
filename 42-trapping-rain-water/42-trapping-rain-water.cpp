class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int ml=height[0];
        int mr=height[n-1];
        int l=1;
        int r=n-2;
        while(l<=r){
            if(ml<mr){
                if(height[l]<ml){
                    ans+=(ml-height[l]);
                }
                else{
                    ml=height[l];
                }
                l++;
            }
            else{
                if(height[r]<mr){
                    ans+=(mr-height[r]);
                }
                else{
                    mr=height[r];
                }
                r--;
            }
        }
        return ans;
    }
};