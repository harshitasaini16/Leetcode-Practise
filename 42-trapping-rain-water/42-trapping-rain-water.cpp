class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int lmx=height[l];
        int r=n-1;
        int s=0;
        int rmx=height[r];
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>lmx){
                    lmx=height[l];
                }
                else{
                    s+=lmx-height[l];
                }
                l++;
            }
            else{
                if(height[r]>rmx){
                    rmx=height[r];
                }
                else{
                    s+=rmx-height[r];
                }
                r--;
            }
        }
        return s;
    }
};