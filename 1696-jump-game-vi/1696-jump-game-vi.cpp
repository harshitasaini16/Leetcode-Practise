class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans=nums[0];
        int n=nums.size();
        priority_queue<pair<int,int>>q;
        q.push({nums[0],0});
        for(int i=1;i<n;i++){
            while(!q.empty() && i-q.top().second>k){
                q.pop();
            }
            if(i==n-1){
                ans=q.top().first+nums[i];
            }
            q.push({q.top().first+nums[i],i});
        }
        return ans;
    }
};