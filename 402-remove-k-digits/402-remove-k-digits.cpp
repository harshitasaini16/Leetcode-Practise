class Solution {
public:
    string removeKdigits(string num, int k) {
        string s=num;
        while(k>0 && s.length()>0){
            while(s.length()>0 && s[0]=='0'){
                s.erase(0,1);
            }
            if(s.length()==0){
                break;
            }
            if(s.length()==1){
                s="";
                break;
            }
            else{
                int x=-1;
                for(int i=0;i<s.length()-1;i++){
                    if(s[i]-'0'>s[i+1]-'0'){
                        x=i;
                        break;
                    }
                }
                // cout<<x<<' ';
                if(x==-1){
                    s.erase(s.length()-1);
                }
                else{
                    s.erase(x,1);
                }
            }
            k--;
            // cout<<s<<' ';
        }
        while(s.length()>0 && s[0]=='0'){
            s.erase(0,1);
        }
        if(s==""){
            return "0";
        }
        return s;
    }
};