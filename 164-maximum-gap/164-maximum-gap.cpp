class Solution {
public:
    int maximumGap(vector<int>& nums) {
        priority_queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        int mx=0;
        int x=q.top();
        q.pop();
        while(!q.empty()){
            int y=q.top();
            q.pop();
            mx=max(mx,abs(x-y));
            x=y;
        }
        return mx;
    }
};