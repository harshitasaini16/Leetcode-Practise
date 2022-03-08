// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int ans=0;
        vector<int>v(V,0);
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                v[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(v[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans++;
            for(auto i:adj[x]){
                v[i]--;
                if(v[i]==0){
                    q.push(i);
                }
            }
        }
        return ans!=V;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends