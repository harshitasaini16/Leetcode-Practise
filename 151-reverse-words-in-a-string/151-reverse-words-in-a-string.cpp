class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string temp="";
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(temp.length()>0){
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                    ans+=" ";
                    temp="";
                }
            }
            else{
                temp+=s[i];
            }
        }
        if(temp.length()>0){
            reverse(temp.begin(),temp.end());
            ans+=temp;
            temp="";
        }
        int i=ans.length()-1;
        while(i>=0 && ans[i]==' '){
            ans.erase(i);
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
