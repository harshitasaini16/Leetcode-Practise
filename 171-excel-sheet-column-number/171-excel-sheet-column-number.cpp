class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0,p=0;
        for(int i=columnTitle.size()-1;i>=0;i--)
        {
            char c=columnTitle[i];
            int val=int(c)-'A'+1;
            ans+=pow(26,p)*val;
            p++;
        }
        return ans;
    }
};