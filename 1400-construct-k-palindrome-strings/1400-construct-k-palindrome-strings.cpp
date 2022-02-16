class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,char>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }    
        int odd=0;
        for(auto i:m){
            if(i.second%2!=0){
                odd++;
            }
        }
        if(odd>k){
            return false;
        }
        if(s.length()<k){
            return false;
        }
        return true;
    }
};