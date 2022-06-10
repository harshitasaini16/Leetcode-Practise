class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int ans=0;
        int j=0;
        for(int i=0;i<s.length();i++){
            j=max(j,m[s[i]]);
            ans=max(ans,i-j+1);
            m[s[i]]=i+1;
        }
        return ans;
    }
};