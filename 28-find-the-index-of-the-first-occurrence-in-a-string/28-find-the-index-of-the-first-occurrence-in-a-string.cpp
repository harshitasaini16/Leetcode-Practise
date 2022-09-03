class Solution {
public:
    int strStr(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<int>lps(m,0);
        int len=0;
        int i=1;
        while(i<m){
            if(s2[i]==s2[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
        i=0;
        int j=0;
        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            if(j==m){
                return i-m;
            }
            else if(i<n && s1[i]!=s2[j]){
                if(j==0){
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
        }
        return -1;
    }
};