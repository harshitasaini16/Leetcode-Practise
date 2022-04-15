class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m;
        for(auto x:t){
            m[x]++;
        }
        int ind=-1;
        int ans=INT_MAX;
        int j=0;
        int c=m.size();
        int i=0,n=s.length();
        while(i<n){
            if(m.find(s[i])!=m.end()){
                m[s[i]]--;
                if(m[s[i]]==0){
                    c--;
                }
            }
            if(c==0){
                if(ans>i-j+1){
                    ans=i-j+1;
                    ind=j;
                }
            }
            while(c==0){
                if(ans>i-j+1){
                    ans=i-j+1;
                    ind=j;
                }
                if(m.find(s[j])!=m.end()){
                    m[s[j]]++;
                    if(m[s[j]]>0){
                        c++;
                    }
                }
                j++;
            }
            i++;
        }
        if(ind==-1){
            return "";
        }
        return s.substr(ind,ans);
        
    }
};