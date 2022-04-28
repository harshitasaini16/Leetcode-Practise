class Solution {
public:
    int lengthOfLastWord(string s) {
       int x=s.length()-1;
        while(x>=0 && s[x]==' '){
            x--;
        }
        if(x<0){
            return 0;
        }
        int y=x;
        while(y>=0 && s[y]!=' '){
            y--;
        }
        return x-y;
    }
};