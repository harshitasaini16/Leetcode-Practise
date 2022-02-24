class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string g="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                reverse(g.begin(),g.end());
                ans+=g;
                ans+=" ";
                g="";
            }
            else{
                g.push_back(s[i]);
            }
        }
        reverse(g.begin(),g.end());
        ans+=g;
        return ans;
    }
};