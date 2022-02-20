class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        int n=s.length();
        int count=m.size();
        int i=0;
        int j=0;
        int start=0;
        int mx=INT_MAX;
        while(i<n){
            if(m.find(s[i])!=m.end()){
                m[s[i]]--;
                if(m[s[i]]==0){
                    count--;
                }
            }
            while(count==0){
                if(mx>i-j+1){
                    mx=i-j+1;
                    start=j;
                }
                if(m.find(s[j])!=m.end()){
                    m[s[j]]++;
                    if(m[s[j]]>0){
                        count++;
                    }
                }
                j++;
            }
            i++;
        }
    if(mx==INT_MAX){
        return "";
    }
        return s.substr(start,mx);
    }
};