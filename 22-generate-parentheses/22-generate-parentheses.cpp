class Solution {
public:
    vector<string>ans;
    void fun(int o,int c,string s){
        if(o<0 || c<0){
            return;
        }
        if(o==0 && c==0){
            ans.push_back(s);
            return;
        }
        if(o>=c){
            fun(o-1,c,s+'(');
        }
        else{
            fun(o-1,c,s+'(');
            fun(o,c-1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        fun(n,n,"");
        return ans;
    }
};