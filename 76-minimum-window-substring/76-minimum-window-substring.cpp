class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        int count=m.size();
        string ans="";
        int mx=INT_MAX;
        int i=0;
        int j=0;
        int n=s.length();
        while(i<n){
            if(m.find(s[i])!=m.end()){
                m[s[i]]--;
                if(m[s[i]]==0){
                    count--;
                }
            }
            while(j<=i && count==0){
                 if(mx>i-j+1){
                    mx=i-j+1;
                    ans=s.substr(j,i-j+1);
                }
                if(m.find(s[j])!=m.end()){
                    m[s[j]]++;
                    if(m[s[j]]==1){
                        count++;
                    }
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};