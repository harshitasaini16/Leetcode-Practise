class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                x=nums[i];
                c=1;
            }
            else if(nums[i]==x){
                c++;
            }
            else{
                c--;
            }
        }
        return x;
    }
};