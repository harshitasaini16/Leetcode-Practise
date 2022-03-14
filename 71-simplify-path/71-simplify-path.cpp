class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        if(path[n-1]!='/'){
            path+='/';
            n++;
        }
        stack<string>s;
        string temp="";
        int i=1;
        while(i<n){
            if(path[i]=='/'){
                if(temp=="" || temp=="."){
                    
                }
                else if(temp==".."){
                    if(s.empty()){
                        
                    }
                    else{
                      s.pop();   
                    }
                }
                else{
                    s.push(temp);
                }
                temp="";
            }
            else{
                temp+=path[i];
            }
            i++;
        }
        stack<string>st;
        string ans="";
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        while(!st.empty()){
            ans+='/';
            ans+=st.top();
            st.pop();
        }
        if(ans.length()==0){
            ans+='/';
        }
        return ans;
    }
};