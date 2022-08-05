class Solution {
public:
    vector<int>lps(string s){
        int n=s.length();
        vector<int>arr(n);
        int len=0,i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                arr[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=arr[len-1];
                }else{
                    arr[i]=0;
                    i++;
                }
            }
        }
        return arr;
    }
    int strStr(string s, string p) {
        vector<int>arr=lps(p);
        int ans=-1;
        if(s==p)
            return 0;
        int i=0,j=0;
        int n=s.length(),m=p.length();
        while(i<n && j<m){
            if(s[i]==p[j]){
                i++;
                j++;
            }
            if(j==m){
                return i-j;
            }
            else if(i<n && s[i]!=p[j]){
                if(j!=0)
                    j=arr[j-1];
                else
                    i++;  
            }
            
        }
        return -1;
    }
};