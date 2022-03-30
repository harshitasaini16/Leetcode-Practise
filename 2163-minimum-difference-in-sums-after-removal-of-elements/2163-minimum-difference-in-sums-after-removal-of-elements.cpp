class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<long long>pq;
        priority_queue<long long,vector<long long>,greater<long long>>pqm;
        int n=nums.size();
        int mn=n/3;
        vector<long long>pref(n,0);
        long long  right=0;
        long long ans=LLONG_MAX;
        for(int i=n-1;i>=mn;i--){
            pqm.push((long long )nums[i]);
            right+=nums[i];
            if(pqm.size()>mn){
                right-=pqm.top();
                pqm.pop();
            }
            if(pqm.size()==mn){
                pref[i]=right;
            }
        }
        long long left=0;
        for(int i=0;i<n-mn;i++){
            pq.push( (long long )nums[i]);
            left+=nums[i];
            if(pq.size()>mn){
                left-=pq.top();
                pq.pop();
            }
            if(pq.size()==mn){
                ans=min(ans,left-pref[i+1]);
            }
            
        }
        return ans;
    }
};