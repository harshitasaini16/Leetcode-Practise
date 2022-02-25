class Solution {
public:
    int compareVersion(string v1, string v2) {
        int x=0;
        int y=0;
        int i=0,j=0;
        int n=v1.length();
        int m=v2.length();
        while(i<n || j<m){
            while(i<n && v1[i]!='.'){
                x=x*10+(v1[i]-'0');
                i++;
            }
            while(j<m && v2[j]!='.'){
                y=y*10+(v2[j]-'0');
                j++;
            }
            if(x>y){
                return 1;
            }
            else if(x<y){
                return -1;
            }
            x=0;
            y=0;
            i++;
            j++;
        }
        return 0;
    }
};