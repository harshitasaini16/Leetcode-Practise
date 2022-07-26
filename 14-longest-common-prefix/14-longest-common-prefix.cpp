class Solution {
public:
    string f(string a,string b){
        string ans="";
        int i=0;
        int j=0;
        while(i<a.length() && j<b.length() && a[i]==b[j]){
            ans+=a[i];
            i++;
            j++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string s=strs[0];
        for(int i=1;i<strs.size();i++){
            s=f(strs[i],s);
        }
        return s;
    }
};