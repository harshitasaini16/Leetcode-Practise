class Solution {
public:
    string fun(string a,string b){
        string c="";
        int i=0;
        int j=0;
        while(i<a.length() && j<b.length() && a[i]==b[j]){
            c.push_back(a[i]);
            i++;
            j++;
        }
        return c;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        for(int i=1;i<strs.size();i++){
            s=fun(s,strs[i]);
        }
        return s;
    }
};