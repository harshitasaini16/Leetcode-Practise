// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    map<int,int>mp;
    bool check(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(int x,string s){
        if(x==s.length()){
            return 0;
        }
        if(mp.find(x)!=mp.end()){
            return mp[x];
        }
        int ans=INT_MAX;
        for(int i=x;i<s.length();i++){
            string g=s.substr(x,i-x+1);
            if(check(g)){
                ans=min(ans,1+f(i+1,s));
            }
        }
         return mp[x]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        mp.clear();
        if(check(str)){
            return 0;
        }
        return f(0,str)-1;
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