class Solution {
public:
    string countAndSay(int n) {
        string ans="";
        for(int i=1;i<=n;i++){
            if(i==1){
                ans="1";
            }
            else{
                string s="";
                char c=ans[0];
                int p=1;
                for(int j=1;j<ans.length();j++){
                    if(ans[j]==ans[j-1]){
                        p++;
                    }
                    else{
                        s+=to_string(p);
                        p=1;
                        s+=c;
                        c=ans[j];
                    }
                }
                s+=to_string(p);
                s+=c;
                ans=s;
            }
        }
        return ans;
    }
};