class Solution {
public:
    int strStr(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        for(int i=0;i<=n-m;i++){
            string g=s1.substr(i,m);
            if(g==s2){
                return i;
            }
        }
        return -1;
    }
};