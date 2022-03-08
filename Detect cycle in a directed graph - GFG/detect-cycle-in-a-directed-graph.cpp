// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool fun(int x, vector<bool>&vis,vector<bool>&fvis,vector<int>adj[]){
        vis[x]=true;
        fvis[x]=true;
        for(auto i:adj[x]){
            if(vis[i]==false && fvis[i]==fals){
                if(fun(i,vis,fvis,adj)){
                    return true;
                }
            }
            else if(fvis[i]==true){
                return true;
            }
        }
        fvis[x]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,false);
        vector<bool>fvis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(fun(i,vis,fvis,adj)){
                    return true;
                }
            }
        }
        return false;
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