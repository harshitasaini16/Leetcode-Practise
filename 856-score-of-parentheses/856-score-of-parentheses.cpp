class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(-1);
            }
            else{
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int t=st.top();
                    st.pop();
                    if(!st.empty() && st.top()==-1){
                        st.pop();
                        st.push(2*t);
                    }
                    else{
                        while(!st.empty() && st.top()!=-1){
                            t+=st.top();
                            st.pop();
                        }
                        if(!st.empty() && st.top()==-1){
                            st.pop();
                            st.push(2*t);
                        }
                        else{
                            st.push(2*t);
                        }
                    }
                }
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};