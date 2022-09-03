class Solution {
public:
    string minWindow(string s, string t) {
        int mx=INT_MAX;
        string ans="";
        int n=s.length();
        map<char,int>m;
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        int j=0;
        int count=m.size();
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                m[s[i]]--;
                if(m[s[i]]==0){
                    count--;
                }
            }
            while(count==0 && j<=i){
                int len=i-j+1;
                if(len<mx){
                    mx=len;
                    ans=s.substr(j,len);
                }
                if(m.find(s[j])!=m.end()){
                    m[s[j]]++;
                    if(m[s[j]]==1){
                       count++;
                    }
                 }
                j++;
            }
        }
        return ans;
    }
};