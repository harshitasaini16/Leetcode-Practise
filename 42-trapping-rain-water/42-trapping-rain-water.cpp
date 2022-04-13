class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lmx=height[0];
        int rmx=height[n-1];
        int l=1;
        int r=n-1;
        int ans=0;
        while(l<=r){
            if(lmx<=rmx){
                if(height[l]<=lmx){
                    ans+=lmx-height[l];
                }
                else{
                    lmx=height[l];
                }
                l++;
            }
            else{
                if(height[r]<=rmx){
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