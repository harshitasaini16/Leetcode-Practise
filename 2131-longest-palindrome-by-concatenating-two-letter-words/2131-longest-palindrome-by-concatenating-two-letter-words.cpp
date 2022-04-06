class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        int ans=0;
        bool f=false;
        for(int i=0;i<n;i++){
            string s1=words[i];
            string s2=words[i];
            swap(s2[0],s2[1]);
            if(mp[s2]>0 && mp[s1]>0 && s1!=s2){
                ans+=4;
                mp[s1]--;
                mp[s2]--;
            }
            else if(mp[s2]>1 && mp[s1]>1 && s1==s2){
                ans+=4;
                mp[s1]--;
                mp[s2]--;
            }
            else if(s1==s2 && f==false && mp[s1]>0){
                ans+=2;
                f=true;
                mp[s1]--;
            }
            // cout<<ans<<' ';
        }
        return ans;
    }
};