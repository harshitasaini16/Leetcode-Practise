class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        string g="";
        if(path[path.length()-1]!='/'){
            path+='/';
        }
        for(int i=1;i<path.length();i++){
            if(path[i]=='/'){
                if(g==".."){
                    if(!s.empty()){
                        s.pop();
                    }
                    g="";
                }
                else if(g=="."){
                    
                }
                else if(g==""){
                    
                }
                else{
                    s.push(g);
                }
                 g="";
            }
            else{
                g+=path[i];
            }
        }
        string ans="";
        stack<string>r;
        while(!s.empty()){
            r.push(s.top());
            s.pop();
        }
        while(!r.empty()){
            ans+='/';
            ans+=r.top();
            r.pop();
        }
        if(ans==""){
            return "/";
        }
        return ans;
    }
};