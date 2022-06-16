class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<s.length();i++){
            int x=i-1;
            int y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                x--;
                y++;
            }
            if(y-x-1>ans.length()){
                ans=s.substr(x+1,y-x-1);
            }
            x=i;
            y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                x--;
                y++;
            }
            if(y-x-1>ans.length()){
                ans=s.substr(x+1,y-x-1);
            }
        }
        return ans;
    }
};