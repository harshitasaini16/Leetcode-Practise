class Solution {
public:
    void fun(string s,vector<int>&a){
        for(int i=0;i<s.length();i++){
            a[s[i]-'a']++;
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        map<vector<int>,vector<string>>m;
        for(int i=0;i<v.size();i++){
            string s=v[i];
            vector<int>a(26,0);
            fun(s,a);
            m[a].push_back(v[i]);
        }
        vector<vector<string>>ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};