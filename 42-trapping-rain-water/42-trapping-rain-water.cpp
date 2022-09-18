class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int lmx=height[0];
        int n=height.size();
        int rmx=height[n-1];
        int l=1;
        int r=n-2;
        while(l<=r){
            if(lmx<=rmx){
                if(height[l]<lmx){
                    ans+=lmx-height[l];
                }
                else{
                    lmx=height[l];
                }
                l++;
            }
            else{
                if(height[r]<rmx){
                    ans+=rmx-height[r];
                }
                else{
                    rmx=height[r];
                }
                r--;
            }
        }
        return ans;
    }
};