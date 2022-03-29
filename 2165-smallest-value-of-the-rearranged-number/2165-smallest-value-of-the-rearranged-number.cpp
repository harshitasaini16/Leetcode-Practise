class Solution {
public:
    long long smallestNumber(long long num) {
        if(num<0){
            string s=to_string(abs(num));
            sort(s.rbegin(),s.rend());
            long long x=0;
            for(int i=0;i<s.length();i++){
                x=x*10+(s[i]-'0');
            }
            return -x;
        }
        else{
            string s=to_string(num);
            sort(s.begin(),s.end());
            int x=0;
            while(x<s.length() && s[x]=='0'){
                x++;
            }
            if(x<s.length()){
                swap(s[0],s[x]);
            }
            cout<<s;
            long long y=0;
            for(int i=0;i<s.length();i++){
                y=y*10+(s[i]-'0');
            }
            return y;
        }
    }
};