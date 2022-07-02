class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& w) {
        unordered_map<string,int>m;
        for(int i=0;i<w.size();i++){
            m[w[i]]++;
        }
        queue<string>q;
        q.push(begin);
        int ans=0;
        while(!q.empty()){
            ans++;
            int size=q.size();
            while(size--){
                string s=q.front();
                q.pop();
                if(s==end){
                    return ans;
                }
                m.erase(s);
                for(int i=0;i<s.length();i++){
                    char d=s[i];
                    for(char c='a';c<='z';c++){
                        s[i]=c;
                        if(m.find(s)!=m.end()){
                            q.push(s);
                        }
                    }
                    s[i]=d;
                }
            }
        }
        return 0;
    }
};