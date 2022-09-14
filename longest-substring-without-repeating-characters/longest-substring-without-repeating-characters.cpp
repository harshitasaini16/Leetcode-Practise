class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int x=-1;
        int ans=0;
        int n=s.length();
        map<char,int>m;
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                x=max(x,m[s[i]]);
            }
            ans=max(ans,i-x);
            m[s[i]]=i;
        }
        return ans;
    }
};