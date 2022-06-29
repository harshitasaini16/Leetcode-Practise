class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        int l=0;
        int x=abs(nums[0]);
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])<x){
                x=abs(nums[i]);
                l=i;
            }
        }
        int r=l+1;
        while(l>=0 && r<n){
            if(abs(nums[l])<=abs(nums[r])){
                ans.push_back(nums[l]*nums[l]);
                l--;
            }
            else{
                ans.push_back(nums[r]*nums[r]);
                r++;
            }
        }
        while(l>=0){
            ans.push_back(nums[l]*nums[l]);
            l--;
        }
        while(r<n){
            ans.push_back(nums[r]*nums[r]);
            r++;
        }
        return ans;
    }
};