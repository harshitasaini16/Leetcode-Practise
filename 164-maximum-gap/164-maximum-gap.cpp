class Solution {
public:
    int maximumGap(vector<int>& nums) {
        priority_queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        int ans=0;
        int x=q.top();
        q.pop();
        while(!q.empty()){
            ans=max(ans,x-q.top());
            x=q.top();
            q.pop();
        }
        return ans;
    }
};