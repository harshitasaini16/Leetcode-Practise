// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    map<string,int>m;
    bool fun(int x,string s){
        if(x==s.length()){
            return true;
        }
        for(int i=x;i<s.length();i++){
            string g=s.substr(x,i-x+1);
            if(m[g]>0){
                if(fun(i+1,s)){
                    return true;
                }
            }
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        for(int i=0;i<B.size();i++){
            m[B[i]]++;
        }
        return fun(0,A);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends