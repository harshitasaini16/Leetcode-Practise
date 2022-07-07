// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        map<int,int>m;
        for(int i=0;i<n;i++){
            if(m[i]==0){
                queue<int>q;
                map<int,int>p;
                p[i]=-1;
                q.push(i);
                m[i]++;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(auto j:adj[x]){
                        if(m[j]==0){
                            q.push(j);
                            p[j]=x;
                            m[j]++;
                        }
                        else if(m[j]!=0 && p[x]!=j){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends