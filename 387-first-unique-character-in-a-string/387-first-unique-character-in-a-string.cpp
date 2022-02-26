class Solution {
public:
    int firstUniqChar(string s) {
        int x=-1;
        map<char,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
           if(m[s[i]]==1){
               return i;
           }
        }
        return x;
    }
};