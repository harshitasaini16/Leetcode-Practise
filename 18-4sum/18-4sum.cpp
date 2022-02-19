class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>v;
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
                    int x=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(x==target){
                        v.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int a=nums[k];
                        int b=nums[l];
                        while(k<l && a==nums[k]){
                            k++;
                        }
                        while(k<l && b==nums[l]){
                            l--;
                        }
                    }
                    else if(x>target){
                        l--;
                    }
                    else if(x<target){
                        k++;
                    }
                }
            }
        }
        return v;
    }
};