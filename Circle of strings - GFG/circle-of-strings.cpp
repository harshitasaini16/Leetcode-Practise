// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void fun(int x,vector<vector<int>>graph,vector<bool>&vis){
        vis[x]=true;
        for(auto i:graph[x]){
            if(vis[i]==false){
                fun(i,graph,vis);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<vector<int>>graph(26);
        vector<int>in(26,0);
        vector<int>out(26,0);
        for(int i=0;i<A.size();i++){
            graph[A[i][0]-'a'].push_back(A[i].back()-'a');
            out[A[i][0]-'a']++;
            in[A[i].back()-'a']++;
        }
        for(int i=0;i<26;i++){
            if(in[i]!=out[i]){
                return false;
            }
        }
        vector<bool>vis(26);
        bool f=false;
        for(int i=0;i<26;i++){
            if(in[i]!=0 && vis[i]==0){
                if(f==true){
                    return false;
                }
                f=true;
                fun(i,graph,vis);
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends