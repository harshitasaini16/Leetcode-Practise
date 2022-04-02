class Solution {
public:
    bool check(string s){
        string g=s;
        reverse(s.begin(),s.end());
        return s==g;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                break;
            }
            i++;
            j--;
        }
        if(i==j){
            return true;
        }
        string g=s;
        g.erase(i,1);
        s.erase(j,1);
        return (check(s) || check(g));
    }
};