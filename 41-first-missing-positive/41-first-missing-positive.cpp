class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool one =false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one=true;
            }
            else if(nums[i]<1 || nums[i]>n){
                nums[i]=1;
            }
        }
        if(one==false){
            return 1;
        }
        for(int i=0;i<n;i++){
            int ind=abs(nums[i]);
            nums[ind-1]=-(abs(nums[ind-1]));
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};