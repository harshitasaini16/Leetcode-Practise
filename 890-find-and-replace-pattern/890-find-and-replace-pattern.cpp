class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>&a, string p) {
        vector<string>v;
        for(int i=0;i<a.size();i++){
            if(p.length()==a[i].length()){
                map<char,char>m;
                map<char,int>mp;
                bool f=true;
                for(int j=0;j<p.length();j++){
                    if((m.find(p[j])==m.end() && (mp[a[i][j]]==0)) || (m[p[j]]==a[i][j] && (mp[a[i][j]]==1))){
                        m[p[j]]=a[i][j];
                        mp[a[i][j]]=1;
                    }
                    else{
                        f=false;
                        break;
                    }
                }
                if(f==true){
                    v.push_back(a[i]);
                }
            }
        }
        return v;
    }
};