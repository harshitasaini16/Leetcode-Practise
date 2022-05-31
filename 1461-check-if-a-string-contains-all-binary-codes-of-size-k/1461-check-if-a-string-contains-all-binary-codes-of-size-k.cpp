class Solution {
public:
    map<string,int>m;
    bool hasAllCodes(string s, int k) {
        // dp.clear();
        m.clear();
        int n=s.length();
        for(int i=0;i<=n-k;i++){
            string g=s.substr(i,k);
            m[g]++;
        }
        return m.size()==pow(2,k);
    }
};