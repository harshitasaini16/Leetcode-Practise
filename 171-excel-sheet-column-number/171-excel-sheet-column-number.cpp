class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        long long x=1;
        for(int i=s.length()-1;i>=0;i--){
            ans+=(s[i]-'A'+1)*x;
            x=x*26;
        }
        return ans;
    }
};