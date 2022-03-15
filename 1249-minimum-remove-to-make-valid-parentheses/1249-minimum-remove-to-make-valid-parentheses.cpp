class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        stack<char>st;
        int n=s.length();
        int open=0,close=0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                close++;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(close>0){
                    close--;
                    ans+='(';
                    open++;
                }
            }
            else if(s[i]==')'){
                if(open>0){
                    ans+=')';
                    open--;
                }
                else{
                    close--;
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};