class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        map<char,int>vis;
        string ans="";
        for(auto i:s){
            m[i]--;
            if(vis[i]==true){
                continue;
            }
            while(!ans.empty() && i<ans.back() && m[ans.back()]>0){
                vis[ans.back()]=false;
                ans.pop_back();
            }
            ans.push_back(i);
            vis[i]=true;
        }
        return ans;
    }
};