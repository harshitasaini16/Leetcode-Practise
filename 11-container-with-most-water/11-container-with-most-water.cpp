class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int lmx=height[0];
        int rmx=height[n-1];
        int j=n-1;
        int ans=0;
        while(i<j){
            int s=(j-i)*min(lmx,rmx);
            cout<<s<<' ';
            ans=max(ans,s);
            if(lmx<=rmx){
                while(i<j && height[i]<=lmx){
                    i++;
                }
                lmx=height[i];
            }
            else{
                int x=height[j];
                while(i<j && height[j]<=rmx){
                    j--;
                }
                rmx=height[j];
            }
        }
        return ans;
    }
};