// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<pair<int,int>>q;
	    q.push({0,0});
	    map<int,int>m;
	    m[0]++;
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        if(x==X){
	            return y;
	        }
	        for(auto i:adj[x]){
	            if(m[i]==0){
	                q.push({i,y+1});
	                m[i]++;
	            }
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends