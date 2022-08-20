class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            int x=i-1;
            int y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                x--;
                y++;
            }
            int len=(y-x)-1;
            string a=s.substr(x+1,len);
            if(len>ans.length()){
                ans=a;
            }
            x=i;
            y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                x--;
                y++;
            }
            len=(y-x)-1;
            a=s.substr(x+1,len);
            if(len>ans.length()){
                ans=a;
            }
        }
        return ans;
    }
};