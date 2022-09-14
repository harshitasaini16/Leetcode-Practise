class Solution {
public:
    vector<string>ans;
    void fun(int x,int y,string s){
        if(x<0 || y<0){
            return;
        }
        if(x==0 && y==0){
            ans.push_back(s);
            return;
        }
        if(x==y){
            fun(x-1,y,s+'(');
        }
        else{
            fun(x-1,y,s+'(');
            fun(x,y-1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        fun(n,n,"");
        return ans;
    }
};