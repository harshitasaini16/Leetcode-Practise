class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                c=1;
                x=nums[i];
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