// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<int>adj[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<vector<int>>ans(N,vector<int>(N,0));
        for(int i=0;i<N;i++){
            map<int,int>m;
            m[i]++;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(auto j:adj[x]){
                    if(m[j]==0){
                        m[j]++;
                        q.push(j);
                    }
                }
            }
            for(int j=0;j<N;j++){
                if(m[j]>0){
                    ans[i][j]=1;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}  // } Driver Code Ends