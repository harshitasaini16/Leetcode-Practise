class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push(-1);
            }else{
                if(stk.top()==-1){
                    stk.pop();
                    stk.push(1);
                }else {
                    int t=stk.top();
                    stk.pop();
                    if(stk.empty()==false and stk.top()==-1){
                        stk.pop();
                        stk.push(2*t);
                    }else{
                        while(stk.empty()==false and stk.top()!=-1){
                            t+=stk.top();
                            stk.pop();
                        }
                        if(stk.empty()==false and stk.top()==-1){
                            stk.pop();
                            stk.push(2*t);
                        }else{
                            stk.push(2*t);
                        }
                    }
                }
            }
        }
        int ans=0;
        while(stk.empty()==false){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};