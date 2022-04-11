class Solution {
public:
    bool fun(string s,string p,int n,int m){
        if(n<=-1 && m<=-1){
            return true;
        }
        if(n<=-1 && p[m]=='*'){
            return fun(s,p,n,m-2);
        }
        if(n==-1 || m==-1){
            return false;
        }
        if(s[n]==p[m]){
            return fun(s,p,n-1,m-1);
        }
        if(p[m]=='*'){
            if(s[n]==p[m-1] || p[m-1]=='.'){
                return (fun(s,p,n-1,m) || fun(s,p,n,m-2));
            }
            else{
                return fun(s,p,n,m-2);
            }
        }
        else if(p[m]=='.'){
            return fun(s,p,n-1,m-1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return fun(s,p,s.length()-1,p.length()-1);
    }
};