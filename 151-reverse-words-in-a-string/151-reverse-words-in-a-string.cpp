class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.length();
        string g="";
        int x=0;
        while(x<n && s[x]==' '){
            x++;
        }
        for(int i=x;i<n;i++){
            if(s[i]!=' '){
                g=g+s[i];
            }
            else if(s[i]==' '){
                if(i!=n-1 && s[i+1]!=' '){
                    g=g+s[i];
                }
            }
        }
        s="";
        for(int i=0;i<g.length();i++){
            if(g[i]!=' '){
                s=s+g[i];
            }
            else{
                reverse(s.begin(),s.end());
                ans+=s;
                ans+=' ';
                s="";
            }
        }
        reverse(s.begin(),s.end());
        ans+=s;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};