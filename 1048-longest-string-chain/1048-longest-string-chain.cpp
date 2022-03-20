class Solution {
public:
    bool static cmp(string a,string b){
        if(a.length()<b.length()){
            return true;
        }
        if(a.length()==b.length()){
            if(a<b){
                return true;
            }
        }
        return false;
    }
    bool fun(string &s1,string &s2){
        if(s1.length()+1!=s2.length()){
            return false;
        }
        int i=0;
        int j=0;
        bool f=false;
        int n=s1.length(),m=s2.length();
        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else if(s1[i]!=s2[j]){
                if(f==true){
                    return false;
                }
                f=true;
                j++;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int mx=1;
        int n=words.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(fun(words[j],words[i]) && dp[j]>=dp[i]){
                    dp[i]=dp[j]+1;
                    mx=max(mx,dp[i]);
                }
            }
    }
        return mx;
    }
};