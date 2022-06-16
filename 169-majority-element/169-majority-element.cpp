class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=0;
        int s=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(x==0){
                x=1;
                s=nums[i];
            }
            else if(nums[i]==s){
                x++;
            }
            else{
                x--;
            }
        }
        return s;
    }
};