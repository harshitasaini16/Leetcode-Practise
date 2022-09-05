class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int>l(n,-1),r(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()>=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                l[i]=1;
            }
            s.push(nums[i]);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                r[i]=1;
            }
            s.push(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(l[i]==1 && r[i]==1){
                return true;
            }
        }
        return false;
    }
};