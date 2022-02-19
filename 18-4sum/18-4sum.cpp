class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>s;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int k=j+1;
                int l=n-1;
                while(k<l){
                    int x=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(x==target){
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
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
        vector<vector<int>>v;
        for(auto i:s){
            v.push_back(i);
        }
        return v;
    }
};