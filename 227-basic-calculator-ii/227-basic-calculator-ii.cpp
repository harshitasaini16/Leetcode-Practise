class Solution {
public:
    int pre(char c){
        if(c=='*' || c=='/'){
           return 2;
        }
        return 1;
    }
    int f(int x,int y,char c){
        if(c=='+'){
            return x+y;
        }
        if(c=='*'){
            return x*y;
        }
        if(c=='/'){
            return x/y;
        }
        if(c=='-'){
            return x-y;
        }
        return 0;
    }
    int calculate(string s) {
        stack<char>op;
        stack<int>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            else if(s[i]>='0' && s[i]<='9'){
                int x=0;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    x=(x*10)+(s[i]-'0');
                    i++;
                }
                i--;
                st.push(x);
            }
            else{
                while(!op.empty() && pre(op.top())>=pre(s[i])){
                    int x=st.top(); st.pop();
                    int y=st.top(); st.pop();
                    st.push(f(y,x,op.top()));
                    op.pop();
                }
                op.push(s[i]);
            }
        }
        while(!op.empty()){
            int x=st.top(); st.pop();
            int y=st.top(); st.pop();
            st.push(f(y,x,op.top()));
            op.pop();
        }
        return st.top();
    }
};