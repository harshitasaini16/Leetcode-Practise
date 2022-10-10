class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1)
            return "";
        int half = n/2;
        for(int i=0;i<half;i++){
            if(palindrome[i]!='a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};