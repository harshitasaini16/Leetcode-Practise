class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        int k=0;
        vector<int>v(n);
        while(k<n){
            if(nums[k]<0){
                v[j]=nums[k];
                k++;
                j+=2;
            }
            else{
                v[i]=nums[k];
                k++;
                i+=2;
            }
        }
        return v;
    }
};