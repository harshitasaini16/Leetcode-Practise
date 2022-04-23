class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m;
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        int j=0;
        int mx=INT_MAX;
        string ans="";
        int count=m.size();
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                m[s[i]]--;
                if(m[s[i]]==0){
                   count--;
                }
            }
            while(count==0){
                if(i-j+1<mx){
                    mx=i-j+1;
                    ans=s.substr(j,mx);
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