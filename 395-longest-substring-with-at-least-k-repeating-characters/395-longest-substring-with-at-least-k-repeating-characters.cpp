class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans=0;
        int n=s.length();
        vector<int>m(26,0);
        int c=0;
        int q=0;
        for(int i=0;i<n;i++){
            m[s[i]-'a']++;
            if(m[s[i]-'a']==k){
                c++;
            }
            if(m[s[i]-'a']==1){
                q++;
            }
            if(c==q){
                ans=i+1;
            }
            else{
                int j=0;
                vector<int>temp=m;
                int t=c;
                int p=q;
                while(j<i && t!=p){
                    temp[s[j]-'a']--;
                    if(temp[s[j]-'a']==k-1){
                        t--;
                    }
                    if(temp[s[j]-'a']==0){
                        p--;
                    }
                    j++;
                }
                if(t==p){
                    ans=max(ans,i-j+1);
                }
            }
        }
        return ans;
    }
};