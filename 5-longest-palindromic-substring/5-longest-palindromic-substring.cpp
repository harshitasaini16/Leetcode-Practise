class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        int mx=0;
        for(int i=0;i<n;i++){
            int x=i;
            int y=i;
            while(x>=0 && y<n && s[x]==s[y]){
                x--;
                y++;
            }
            int len=y-x-1;
            if(len>mx){
                mx=len;
                ans=s.substr(x+1,len);
            }
            x=i;
            y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                x--;
                y++;
            }
            len=y-x-1;
            if(len>mx){
                mx=len;
                ans=s.substr(x+1,len);
            }
        }
        return ans;
    }
};