class Solution {
public:
    string generateTheString(int n) {
        string s="";
        if(n%2!=0){
            for(int i=0;i<n;i++){
                s.push_back('a');
            }
        }
        else{
            for(int i=1;i<n;i++){
                s.push_back('a');
            }
            s.push_back('b');
        }
        return s;
    }
};