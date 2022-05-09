class Solution {
public:
    void fun(int i,string digits,string s,vector<string>&v){
        if(i==digits.size()){
            v.push_back(s);
            return;
        }
        if(digits[i]=='2'){
             fun(i+1,digits,s+'a',v);
             fun(i+1,digits,s+'b',v);
             fun(i+1,digits,s+'c',v);
        }
        if(digits[i]=='3'){
            fun(i+1,digits,s+'d',v);
             fun(i+1,digits,s+'e',v);
             fun(i+1,digits,s+'f',v);
        }
        if(digits[i]=='4'){
            fun(i+1,digits,s+'g',v);
             fun(i+1,digits,s+'h',v);
             fun(i+1,digits,s+'i',v);
        }
        if(digits[i]=='5'){
            fun(i+1,digits,s+'j',v);
             fun(i+1,digits,s+'k',v);
             fun(i+1,digits,s+'l',v);
        }
        if(digits[i]=='6'){
            fun(i+1,digits,s+'m',v);
             fun(i+1,digits,s+'n',v);
             fun(i+1,digits,s+'o',v);
        }
        if(digits[i]=='7'){
            fun(i+1,digits,s+'p',v);
             fun(i+1,digits,s+'q',v);
             fun(i+1,digits,s+'r',v);
            fun(i+1,digits,s+'s',v);
        }
        if(digits[i]=='8'){
            fun(i+1,digits,s+'t',v);
             fun(i+1,digits,s+'u',v);
             fun(i+1,digits,s+'v',v);
        }
        if(digits[i]=='9'){
            fun(i+1,digits,s+'w',v);
             fun(i+1,digits,s+'x',v);
             fun(i+1,digits,s+'y',v);
             fun(i+1,digits,s+'z',v);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>v;
        string s="";
        fun(0,digits,s,v);
        if(digits.size()==0)
            return {};
        return v;
    }
};