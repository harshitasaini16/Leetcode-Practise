class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        for(int i=0;i<s.length();i++){
            if(s[i]!='#'){
                s1.push(s[i]);
            }
            else if(s[i]=='#' && !s1.empty()){
                s1.pop();
            }
        }
        stack<char>s2;
        for(int i=0;i<t.length();i++){
            if(t[i]!='#'){
                s2.push(t[i]);
            }
            else if(t[i]=='#' && !s2.empty()){
                s2.pop();
            }
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        while(!s1.empty()){
            if(s1.top()!=s2.top()){
                return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }
};