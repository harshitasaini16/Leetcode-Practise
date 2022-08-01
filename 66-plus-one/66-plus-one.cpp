class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int c=1;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int x=digits[i]+c;
            ans.push_back(x%10);
            c=x/10;
        }
        if(c>0){
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};