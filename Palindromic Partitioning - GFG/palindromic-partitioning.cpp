// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501];
    int fun(int x,string s){
        if(x>=s.length()){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        string h=s.substr(x,s.length()-x);
        string g=h;
        reverse(h.begin(),h.end());
        if(g==h){
           return dp[x]=0;
        }
        int ans=INT_MAX;
        for(int i=x;i<s.length();i++){
            string h=s.substr(x,i-x+1);
            string g=h;
            reverse(h.begin(),h.end());
            if(g==h){
                ans=min(ans,fun(i+1,s));
            }
        }
        return dp[x]=ans+1;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return fun(0,str);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends