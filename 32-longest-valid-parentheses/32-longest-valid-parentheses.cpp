class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    st.push(i);
                }
                else if(s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        int ans=0;
        int a=n;
        while(!st.empty()){
            int b=st.top();
            ans=max(ans,a-b-1);
            a=st.top();
            st.pop();
        }
        ans=max(ans,a);
        return ans;
    }
};