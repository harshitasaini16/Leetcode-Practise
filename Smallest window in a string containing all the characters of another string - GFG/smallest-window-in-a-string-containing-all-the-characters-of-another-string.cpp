//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        string ans="";
        int mx=INT_MAX;
        int n=s.length();
        int m=p.length();
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++){
            mp[p[i]]++;
        }
        int x=mp.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    x--;
                }
            }
            while(j<=i && x==0){
                if(mx>(i-j+1)){
                    mx=i-j+1;
                    ans=s.substr(j,i-j+1);
                }
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]++;
                    if(mp[s[j]]==1){
                       x++;
                    }
                }
                j++;
            }
        }
        if(mx==INT_MAX){
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends