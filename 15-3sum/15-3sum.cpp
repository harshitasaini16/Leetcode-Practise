class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];
                if(s==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int x=nums[j];
                    int y=nums[k];
                    while(j<k && nums[j]==x){
                        j++;
                    }
                    while(j<k && nums[k]==y){
                        k--;
                    }
                }
                else if(s<0){
                    j++;
                }
                else if(s>0){
                    k--;
                }
            }
        }
        return ans;
    }
};