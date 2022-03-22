class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int c1=0,c2=0;
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x'){
                    c1++;
                }
                else{
                    c2++;
                }
            }
        }
        int s=(c1/2)+(c2/2);
        int x=c1%2;
        int y=c2%2;
        if(x!=y){
            return -1;
        }
        if(x==1){
            s+=2;
        }
        return s;
    }
};