class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int n=nums.size();
        int j=1;
        int c=1;
        while(i<n){
            if(nums[i]==nums[i-1]){
                if(c==2){
                    i++;
                    continue;
                }
                else{
                    nums[j]=nums[i];
                    i++;
                    j++;
                    c++;
                }
            }
            else{
                nums[j]=nums[i];
                c=1;
                i++;
                j++;
            }
        }
        return j;
    }
};