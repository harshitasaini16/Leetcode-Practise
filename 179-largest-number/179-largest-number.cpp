class Solution {
public:
    static bool cmp(int a,int b){
       string s1=to_string(a);
        string s2=to_string(b);
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }
        while(ans.size()>1 && ans[0]=='0'){
            ans.erase(0,1);
        }
        return ans;
    }
};
