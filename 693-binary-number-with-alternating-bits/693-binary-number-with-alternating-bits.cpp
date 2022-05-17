class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s="";
        while(n>0){
            if(n%2==0){
                s+='1';
            }
            else{
                s+='0';
            }
            n/=2;
        }
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                return false;
            }
        }
        return true;
    }
};