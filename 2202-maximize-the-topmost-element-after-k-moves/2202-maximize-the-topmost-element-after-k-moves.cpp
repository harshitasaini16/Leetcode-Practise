class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            if(k%2==0){
                return nums[0];
            }
            else{
                return -1;
            }
        }
        if(k==0){
            return nums[0];
        }
        if(n==1 && k>0){
            return -1;
        }
        if(k==1){
            return nums[1];
        }
        priority_queue<int>q;
        int i=0;
        while(i<n && k>1){
            q.push(nums[i]);
            i++;
            k--;
        }
        if(i<n-1){
            return max(q.top(),nums[i+1]);
        }
        return q.top();
    }
};