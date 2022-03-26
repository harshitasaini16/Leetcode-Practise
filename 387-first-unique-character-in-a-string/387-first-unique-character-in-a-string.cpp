class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>m;
        int x=-1;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=s.length()-1;i>=0;i--){
            if(m[s[i]]==1){
                x=i;
            }
        }
        return x;
    }
};