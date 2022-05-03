class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int x=0;
        int n=nums.size();
        while(x<n && nums[x]==v[x]){
            x++;
        }
        if(x==n){
            return 0;
        }
        int y=nums.size()-1;
        while(y>=0 && nums[y]==v[y]){
            y--;
        }
        return y-x+1;
    }
};