class Solution {
public:
    int strStr(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<int>lps(m,0);
        int i=1;
        int len=0;
        while(i<m){
            if(p[i]==p[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        i=0;
        int j=0;
        while(i<n && j<m){
            if(s[i]==p[j]){
                j++;
                i++;
                if(j>=m){
                   return i-m;
                }
                if(i>=n){
                    return -1;
                }
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};