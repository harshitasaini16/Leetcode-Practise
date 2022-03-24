class Solution {
public:
    int balancedString(string s) {
        int n=s.length();
        int x=n/4;
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        int j=0;
        int ans=n;
        for(int i=0;i<n;i++){
            m[s[i]]--;
            while(j<n && m['Q']<=x && m['W']<=x && m['E']<=x && m['R']<=x){
                ans=min(ans,i-j+1);
                m[s[j]]++;
                j++;
            }
        }
        return ans;
    }
};