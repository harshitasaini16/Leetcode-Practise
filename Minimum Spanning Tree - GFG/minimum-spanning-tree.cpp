//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int dis[V];
        bool vis[V];
        for(int i=0;i<V;i++){
            dis[i]=INT_MAX;
            vis[i]=false;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        // vis[0]=true;
        dis[0]=0;
        while(!q.empty()){
            int y=q.top().second;
            q.pop();
            vis[y]=true;
            for(auto i:adj[y]){
                if(vis[i[0]]==false && dis[i[0]]>i[1]){
                    dis[i[0]]=i[1];
                    q.push({i[1],i[0]});
                }
            }
        }
        return accumulate(dis,dis+V,0);
    }
};


//{ Driver Code Starts.


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