class Solution {
public:
    int f(char c){
        if(c=='I'){
            return 1;
        }
        if(c=='V'){
            return 5;
        }
        if(c=='X'){
            return 10;
        }
        if(c=='L'){
            return 50;
        }
        if(c=='C'){
            return 100;
        }
        if(c=='D'){
            return 500;
        }
        if(c=='M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int n=s.length();
        int ans=f(s[n-1]);
        for(int i=n-2;i>=0;i--){
            int x=f(s[i]);
            int y=f(s[i+1]);
            if(x<y){
                ans-=x;
            }
            else{
                ans+=x;
            }
        }
        return ans;
    }
};