// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int f(vector<int>key,vector<bool>vis){
	    int x=INT_MAX,y;
	    for(int i=0;i<key.size();i++){
	        if(vis[i]==false && key[i]<x){
	            x=key[i];
	            y=i;
	        }
	    }
	    return y;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int s=0;
        vector<int>key(V,INT_MAX);
        vector<bool>vis(V,false);
        vector<int>parent(V,-1);
        key[0]=0;
        for(int i=1;i<V;i++){
            int x=f(key,vis);
            vis[x]=true;
            for(auto j:adj[x]){
                if(vis[j[0]]==false && key[j[0]]>j[1]){
                    key[j[0]]=j[1];
                    parent[j[0]]=x;
                }
            }
        }
        return accumulate(key.begin(),key.end(),0);
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends