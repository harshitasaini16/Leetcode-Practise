class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int x=INT_MAX;
        int y;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];
                if(abs(s-target)<x){
                    x=abs(s-target);
                    y=s;
                }
                if(s==target){
                    return target;
                }
                else if(s>target){
                    k--;
                }
                else if(s<target){
                    j++;
                }
            }
        }
        return y;
    }
};