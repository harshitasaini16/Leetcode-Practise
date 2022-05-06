class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        stack<pair<char,int>>st;
        int i=0;
        while(i<n){
            if(st.empty()){
                st.push({s[i],1});
                i++;
            }
            else{
                char c=st.top().first;
                int x=st.top().second;
                if(c!=s[i]){
                    st.push({s[i],1});
                }
                else{
                    x++;
                    st.pop();
                    if(x!=k){
                        st.push({s[i],x});
                    }
                }
                i++;
            }
        }
        string ans="";
        while(!st.empty()){
            char c=st.top().first;
            int x=st.top().second;
            st.pop();
            while(x--){
                ans.push_back(c);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};