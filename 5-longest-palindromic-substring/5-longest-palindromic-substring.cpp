class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int ans=1;
        string st=s.substr(0,1);
        for(int i=0;i<n;i++){
            int l=i;
            int r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            string sc=s.substr(l+1,r-l-1);
            cout<<sc<<' ';
            if(sc.length()>ans){
                ans=sc.length();
                st=sc;
            }
            l=i-1;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            sc=s.substr(l+1,r-l-1);
            cout<<sc<<' ';
            if(sc.length()>ans){
                ans=sc.length();
                st=sc;
            }
        }
        return st;
    }
};