class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count=1;
                x=nums[i];
            }
            else if(nums[i]==x){
                count++;
            }
            else{
                count--;
            }
        }
        return x;
    }
};