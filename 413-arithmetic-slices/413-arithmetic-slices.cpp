class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        int ans=0;
        int d=0;
        for(int i=1;i<n;i++){
            if(c==0){
                int x=nums[i]-nums[i-1];
                d=x;
                c++;
            }
            else{
                int x=nums[i]-nums[i-1];
                if(x==d){
                    ans+=c;
                    c++;
                }
                else{
                    c=1;
                    d=x;
                }
            }
        }
        return ans;
    }
};