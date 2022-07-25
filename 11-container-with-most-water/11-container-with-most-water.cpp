class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0;
        int r=h.size()-1;
        int ans=0;
        while(l<r){
            if(h[l]<=h[r]){
                int s=(r-l)*h[l];
                ans=max(ans,s);
                int x=h[l];
                while(l<=r && h[l]<=x){
                    l++;
                 }
            }
            else{
                int s=(r-l)*h[r];
                ans=max(ans,s);
                int y=h[r];
                while(l<=r && h[r]<=y){
                    r--;
            }
            }
            
            
            
            
        }
        return ans;
    }
};