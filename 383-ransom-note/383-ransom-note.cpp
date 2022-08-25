class Solution {
public:
    bool canConstruct(string s1, string s2) {
        map<char,int>m;
        for(int i=0;i<s2.length();i++){
            m[s2[i]]++;
        }
        for(int i=0;i<s1.length();i++){
            if(m[s1[i]]==0){
                return false;
            }
            m[s1[i]]--;
        }
        return true;
    }
};