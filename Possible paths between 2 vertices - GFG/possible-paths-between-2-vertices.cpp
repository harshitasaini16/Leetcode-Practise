// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int ans=0;
    void fun(int s,vector<int> adj[],int d){
        if(s==d){
            ans++;
            return;
        }
        for(auto i:adj[s]){
            fun(i,adj,d);
        }
    }
    int countPaths(int n, vector<int> adj[], int s, int d) {
        // Code here
        // vector<int>adj[n];
        // for(int i=0;i<;i++){
        //     adj[ad[i][0]].push_back(ad[i][1]);
        // }
        fun(s,adj,d);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends