class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n=v1.size();
        int m=v2.size();
        int i=0,j=0;
        int n1=0,n2=0;
        while(i<n or j<m){
            while(i<n and v1[i]!='.'){
                n1=n1*10+(v1[i]-'0');
                i++;
            }
            while(j<m and v2[j]!='.'){
                n2=n2*10+(v2[j]-'0');
                j++;
            }
            if(n1<n2){
                return -1;
            }else if(n1>n2){
                return 1;
            }
            i++;
            j++;
            n1=0,n2=0;
        }
        return 0;
    }
};