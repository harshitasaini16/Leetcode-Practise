class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool f=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                f=true;
            }
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }
        if(f==false){
            return 1;
        }
        for(int i=0;i<n;i++){
            int in=abs(nums[i]);
            nums[in-1]=-(abs(nums[in-1]));
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};