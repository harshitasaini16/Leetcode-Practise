class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,a=0,count2=0,b=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count1>0 && a==nums[i]){
                count1++;
            }
            else if(count2>0 && b==nums[i]){
                count2++;
            }
            else if(count1==0){
                count1++;
                a=nums[i];
            }
            else if(count2==0){
                count2++;
                b=nums[i];
            }
            else{
                count1--;
                count2--;
            }
        }
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a){
                s1++;
            }
            if(nums[i]==b){
                s2++;
            }
        }
        vector<int>v;
        if(s1>(n/3)){
            v.push_back(a);
        }
        if(s2>(n/3) && a!=b){
            v.push_back(b);
        }
        return v;
    }
};