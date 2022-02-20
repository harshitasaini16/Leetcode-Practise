class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int mx=0;
        int x=-1;
        map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                x=max(x,m[s[i]]);
            }
            m[s[i]]=i;
            mx=max(mx,i-x);
        }
        return mx;
    }
};
