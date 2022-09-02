class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ans=0;
        while(l<r){
            int mn=min(height[l],height[r]);
            int area=mn*(r-l);
            ans=max(ans,area);
            while(l<r && height[l]<=mn){
                l++;
            }
            while(l<r && height[r]<=mn){
                r--;
            }
        }
        return ans;
    }
};