class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                x++;
            }
        }
        if(x==0){
            return 1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                nums[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(abs(nums[i])>1){
                int x=abs(nums[i])-2;
                if(x<n && nums[x]>0){
                    nums[x]=-nums[x];
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<nums[i]<<' ';
        // }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+2;
            }
        }
        return n+1;
    }
};