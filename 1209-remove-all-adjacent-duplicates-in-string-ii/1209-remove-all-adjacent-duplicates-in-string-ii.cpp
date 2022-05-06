class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                if(st.top().first==s[i]){
                    st.top().second++;
                }
                else{
                    st.push({s[i],1});
                }
            }
            int x=st.top().second;
            if(x==k){
                st.pop();
            }
        }
        string h="";
        while(!st.empty()){
            int x=st.top().second;
            while(x>0){
                h.push_back(st.top().first);
                x--;
            }
            st.pop();
        }
        reverse(h.begin(),h.end());
        return h;
    }
};