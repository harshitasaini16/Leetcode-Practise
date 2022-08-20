class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        map<string,vector<string>>m;
        for(int i=0;i<v.size();i++){
            string s=v[i];
            sort(s.begin(),s.end());
            m[s].push_back(v[i]);
        }
        vector<vector<string>>ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};