class Solution {
public:
    bool fun(string s,unordered_map<char,int>m){
        for(int i=0;i<s.length();i++){
            if(m[s[i]]<=0){
                return false;
            }
            m[s[i]]--;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s2.length();
        int m=s1.length();
        if(n<m){
            return false;
        }
        unordered_map<char,int>m2;
        for(int i=0;i<m;i++){
            m2[s2[i]]++;
        }
        if(fun(s1,m2)){
            return true;
        }
        for(int i=m;i<n;i++){
            m2[s2[i-m]]--;
            m2[s2[i]]++;
            if(fun(s1,m2)){
                return true;
            }
        }
        return false;
    }
};