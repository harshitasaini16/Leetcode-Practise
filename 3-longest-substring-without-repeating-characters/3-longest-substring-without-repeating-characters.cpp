class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>m;
        int ans=0;
        int x=-1;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                x=max(x,m[s[i]]);
            }
            ans=max(ans,i-x);
            m[s[i]]=i;
        }
        return ans;
    }
};