class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        int j=1;
        int c=1;
        int x=nums[0];
        while(i<n && j<n){
            if(x==nums[i]){
                if(c==1){
                   swap(nums[i],nums[j]);
                    i++;
                    j++;
                    c++;
                }
                else if(c>=2){
                   i++;
                   c++;
                }
            }
            else{
                x=nums[i];
                swap(nums[i],nums[j]);
                i++;
                j++;
                c=1;
            }
        }
        return j;
    }
};