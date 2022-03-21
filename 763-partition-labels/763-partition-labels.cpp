class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int n=s.length();
        map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        int mx=0;
        int x=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,m[s[i]]);
            if(mx==i){
                ans.push_back(i-x);
                x=i;
            }
        }
        return ans;
    }
};