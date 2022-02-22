class Solution {
public:
    int titleToNumber(string col) {
        int n=col.length();
        int s=0;
        int x=0;
        for(int i=n-1;i>=0;i--){
            int y=col[i]-'A'+1;
            s+=pow(26,x)*y;
            x++;
        }
        return s;
    }
};