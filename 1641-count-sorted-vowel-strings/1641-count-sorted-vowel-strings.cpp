class Solution {
public:
    int ans;
    void fun(int x,int n,char c){
        if(x==n){
            ans++;
            return;
        }
        string s="aeiou";
        for(int i=0;i<s.length();i++){
            if(c<=s[i]){
                fun(x+1,n,s[i]);
            }
        }
    }
    int countVowelStrings(int n) {
        ans=0;
        fun(0,n,' ');
        return ans;
    }
};