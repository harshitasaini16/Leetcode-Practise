class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0;
        int ans=0;
        int r=h.size()-1;
        while(l<r){
            int s=min(h[l],h[r])*(r-l);
            ans=max(ans,s);
            if(h[l]<=h[r]){
                int x=h[l];
                while(l<r && h[l]==x){
                    l++;
                }
            }
            else{
                int y=h[r];
                while(l<r && h[r]==y){
                    r--;
                }
            }
        }
        return ans;
    }
};