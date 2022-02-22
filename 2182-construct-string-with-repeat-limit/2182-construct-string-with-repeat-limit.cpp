class Solution {
public:
    string repeatLimitedString(string s, int r) {
        map<char,int>m;
        int n=s.length();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        priority_queue<pair<char,int>>q;
        for(auto i:m){
            q.push({i.first,i.second});
        }
        string ans="";
        while(!q.empty()){
            int l=ans.length();
            char c=q.top().first;
            int x=q.top().second;
            q.pop();
            if(l==0 || ans[l-1]!=c){
                if(x<=r){
                    for(int i=0;i<x;i++){
                        ans.push_back(c);
                    }
                }
                else if(x>r){
                    for(int i=0;i<r;i++){
                        ans.push_back(c);
                    }
                    q.push({c,x-r});
                }
            }
            else if(ans[l-1]==c){
                if(q.empty()){
                    break;
                }
                char cd=q.top().first;
                int xd=q.top().second;
                q.pop();
                ans.push_back(cd);
                if(xd>1){
                    q.push({cd,xd-1});
                }
                q.push({c,x});
            }
        }
        return ans;
    }
};