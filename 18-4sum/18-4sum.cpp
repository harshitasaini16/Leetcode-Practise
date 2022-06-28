class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                    continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long s=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(s==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int x=nums[k];
                        while(k<l && nums[k]==x){
                            k++;
                        }
                        int y=nums[l];
                        while(k<l && nums[l]==y){
                            l--;
                        }
                    }
                    else if(s>target){
                        l--;
                    }
                    else if(s<target){
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};