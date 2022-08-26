class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& v) {
        map<string,int>m;
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        queue<pair<string,int>>q;
        q.push({bw,1});
        m[bw]=0;
        while(!q.empty()){
            string s=q.front().first;
            int x=q.front().second;
            if(s==ew){
                return x;
            }
            q.pop();
            for(int i=0;i<s.length();i++){
                char ch=s[i];
                for(char c='a';c<='z';c++){
                    if(c!=ch){
                        s[i]=c;
                        if(m[s]>0){
                            m[s]=0;
                            q.push({s,x+1});
                        }
                    }
                }
                s[i]=ch;
            }
        }
        return 0;
    }
};