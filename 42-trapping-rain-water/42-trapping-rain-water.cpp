class Solution {
public: 
    int trap(vector<int>& height) {
        int n=height.size();
        int i=1;
        int j=n-2;
        int l=height[0];
        int r=height[n-1];
        int ans=0;
        while(i<=j){
            if(l<=r){
                if(height[i]<l){
                    ans+=l-height[i];
                }
                else{
                    l=height[i];
                }
                i++;
            }
            else{
                if(height[j]<r){
                    ans+=r-height[j];
                }
                else{
                    r=height[j];
                }
                j--;
            }
        }
        return ans;
    }
};