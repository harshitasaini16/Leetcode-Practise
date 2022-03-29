class Solution {
public:
    int minimumTime(string s) {
        int n=s.length();
        vector<int>pref(n),suf(n);
        if(s[0]=='1'){
            pref[0]=1;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                pref[i]=min(pref[i-1]+2,i+1);
            }else{
                pref[i]=pref[i-1];
            }
        }
        if(s[n-1]=='1'){
            suf[n-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1'){
                suf[i]=min(suf[i+1]+2,n-i);
            }else{
                suf[i]=suf[i+1];
            }
        }
        int ans=min(suf[0],pref[n-1]);
        for(int i=0;i<n-1;i++){
            ans=min(ans,pref[i]+suf[i+1]);
        }
        return ans;
    }
};