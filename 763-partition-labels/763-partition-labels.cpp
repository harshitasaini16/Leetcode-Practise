class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int>ans;
        map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        int j=-1;
        int mx=m[s[0]];
        for(int i=0;i<n;i++){
            mx=max(mx,m[s[i]]);
            if(mx==i){
                ans.push_back(i-j);
                mx=m[s[i]];
                j=i;
            }
        }
        return ans;
    }
};