class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>q;
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                q.push(nums[i]);
                mn=min(mn,nums[i]);
            }
            else{
                q.push(nums[i]*2);
                mn=min(mn,nums[i]*2);
            }
        }
        int ans=INT_MAX;
        while(q.top()%2==0){
            ans=min(ans,q.top()-mn);
            mn=min(mn,q.top()/2);
            q.push(q.top()/2);
            q.pop();
        }
        ans=min(ans,q.top()-mn);
        return ans;
    }
};