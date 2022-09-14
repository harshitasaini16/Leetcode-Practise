class Solution {
public:
    vector<int>fun(string s){
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        return v;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>m;
        for(int i=0;i<strs.size();i++){
            vector<int>v=fun(strs[i]);
            m[v].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};