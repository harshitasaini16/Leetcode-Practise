class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,x1=0,x2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==x1){
                c1++;
            }
            else if(nums[i]==x2){
                c2++;
            }
            else if(c1==0){
                c1++;
                x1=nums[i];
            }
            else if(c2==0){
                c2++;
                x2=nums[i];
            }
            
            else{
                c1--;
                c2--;
            }
        }
        int d1=0,d2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==x1){
                d1++;
            }
            else if(nums[i]==x2){
                d2++;
            }
        }
        int p=n/3;
        vector<int>v;
        if(d1>p){
            v.push_back(x1);
        }
        if(d2>p && x1!=x2 && d2>0){
            v.push_back(x2);
        }
        return v;
    }
};