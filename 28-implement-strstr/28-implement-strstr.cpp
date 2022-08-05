class Solution {
public:
    int strStr(string txt, string pat) {
        int n=txt.length();
        int m=pat.length();
        int lps[m];
        lps[0]=0;
        int i=1;
        int len=0;
        while(i<m){
            if(pat[i]==pat[len]){
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
            if(txt[i]==pat[j]){
                i++;
                j++;
            }
            if(j==m){
                return i-m;
                j=lps[m-j];
            }
            else if(i<n && pat[j]!=txt[i]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i=i+1;
                }
            }
        }
        return -1;
    }
};