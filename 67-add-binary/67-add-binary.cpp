class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int c=0;
        int n=a.length(),m=b.length();
        while(n>0 && m>0){
            int x=(a[n-1]-'0')+(b[m-1]-'0')+c;
            if(x==0){
                ans+='0';
                c=0;
            }
            else if(x==1){
                ans+='1';
                c=0;
            }
            else if(x==2){
                ans+='0';
                c=1;
            }
            else if(x==3){
                ans+='1';
                c=1;
            }
            n--;
            m--;
        }
        while(n>0){
            int x=(a[n-1]-'0')+c;
            if(x==0){
                ans+='0';
                c=0;
            }
            else if(x==1){
                ans+='1';
                c=0;
            }
            else if(x==2){
                ans+='0';
                c=1;
            }
            else if(x==3){
                ans+='1';
                c=1;
            }
            n--;
        }
        while(m>0){
            int x=(b[m-1]-'0')+c;
            if(x==0){
                ans+='0';
                c=0;
            }
            else if(x==1){
                ans+='1';
                c=0;
            }
            else if(x==2){
                ans+='0';
                c=1;
            }
            else if(x==3){
                ans+='1';
                c=1;
            }
            m--;
        }
        if(c>0){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};