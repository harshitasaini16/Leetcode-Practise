class Solution {
public:
    map<string,int>m;
    vector<string>ans;
    void fun(int i,string s,string g){
        if(i==s.length()){
            ans.push_back(g);
            return;
        }
        if(g.length()>0){
            g=g+" ";
        }
        string x="";
        for(int j=i;j<s.length();j++){
            x=x+s[j];
            if(m[x]>0){
                fun(j+1,s,g+x);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>&d) {
        ans.clear();
        m.clear();
        for(int i=0;i<d.size();i++){
            m[d[i]]++;
        }
        fun(0,s,"");
        return ans;
    }
};