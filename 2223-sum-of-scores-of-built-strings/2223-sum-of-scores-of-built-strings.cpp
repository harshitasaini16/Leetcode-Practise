class Solution {
public:
    long long sumScores(string s) {
        int n=s.length();
        vector<int>z(n);
        for(int i=1,l=0,r=0; i<n ;i++){
            if(i<=r){
                z[i]=min(r-i+1,z[i-l]);
            }
            while(i+z[i]<n && s[z[i]]==s[z[i]+i]){
                z[i]++;
            }
            if(i+z[i]-1>r){
                l=i;
                r=z[i]+i-1;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=z[i];
        }
        return ans+s.length();
    }
};