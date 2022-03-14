class Solution {
public:
    string fun(string s){
        string a[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        int x=0;
        for(int i=0;i<s.length();i++){
            x=(x*10)+(s[i]-'0');
        }
        // cout<<x<<' ';
        return a[x-1];
    }
    string freqAlphabets(string s) {
        int n=s.length();
        string ans="";
        int i=0;
        while(i<n){
            if(s[i]=='#'){
                i++;
                continue;
            }
            int j=i+2;
            if(j<n && s[j]=='#'){
                ans+=fun(s.substr(i,2));
                i=i+2;
            }
            else{
                ans+=fun(s.substr(i,1));
                i++;
            }
        }
        return ans;
    }
};