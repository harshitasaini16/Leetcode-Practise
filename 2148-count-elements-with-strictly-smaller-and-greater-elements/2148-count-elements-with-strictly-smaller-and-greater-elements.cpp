class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        if(n==1 || n==2){
            return 0;
        }
        int j=n-1;
        while(i<n && nums[i]==nums[0]){
            i++;
        }
        while(j>=0 && nums[j]==nums[n-1]){
            j--;
        }
        if(j>=i){
            return j-i+1;
        }
        return 0;
    }
};