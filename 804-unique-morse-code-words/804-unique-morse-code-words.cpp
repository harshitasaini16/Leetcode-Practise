class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string,int>m;
        string a[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.size();i++){
            string s=words[i];
            string temp="";
            for(int j=0;j<s.length();j++){
                int x=s[j]-'a';
                temp+=a[x];
            }
            m[temp]++;
        }
        return m.size();
    }
};