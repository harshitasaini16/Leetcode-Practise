// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        queue<int>q;
        q.push(c);
        map<int,int>vis;
        vis[c]++;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:adj[x]){
                if(x==c && y==d){
                    continue;
                }
                else if(x==d && y==c){
                    continue;
                }
                else if(vis[y]==0){
                    q.push(y);
                    vis[y]++;
                }
            }
        }
        return vis[d]==0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends