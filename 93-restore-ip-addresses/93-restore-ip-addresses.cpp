class Solution {
public:
    vector<string>ans;
    bool valid(string s){
        int n=0;
        for(int i=0;i<s.length();i++){
            n=n*10+(s[i]-'0');
        }
        return (n>=0 && n<=255);
    }
    void fun(int x,string &s,int d,string g){
        if(x==s.length()){
            if(d==4){
                g.pop_back();
                ans.push_back(g);
            }
            return;
        }
        if(s[x]=='0'){
            fun(x+1,s,d+1,g+'0'+'.');
            return;
        }
        string h="";
        for(int i=x;i<min((int)s.length(),x+4);i++){
            h+=s[i];
            if(valid(h)){
                fun(i+1,s,d+1,g+h+'.');
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]<'0' || s[i]>'9'){
                return ans;
            }
        }
        ans.clear();
        string g="";
        fun(0,s,0,g);
        return ans;
    }
};