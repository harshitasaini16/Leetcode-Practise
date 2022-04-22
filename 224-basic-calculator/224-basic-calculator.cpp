class Solution {
public:
    int fun(int &i,string &s){
        int ans=0;
        int p=1;
        while(i<s.length() && s[i]!=')'){
            if(s[i]=='+' || s[i]==' '){
                i++;
            }
            else if(s[i]=='-'){
                i++;
                p=-1;
            }
            else if(s[i]=='('){
                i++;
                if(p==1){
                    ans+=fun(i,s);
                }
                else{
                    ans-=fun(i,s);
                }
                p=1;
            }
            else{
                int num=0;
                while(i<s.length() && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                if(p==1){
                    ans+=num;
                }
                else{
                    ans-=num;
                }
                p=1;
            }
        }
        i++;
        return ans;
    }
    int calculate(string s) {
        int i=0;
        return fun(i,s);
    }
};