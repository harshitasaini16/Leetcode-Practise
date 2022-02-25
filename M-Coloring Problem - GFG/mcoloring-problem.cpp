// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool check(vector<int>color,vector<int>adj[],int n,int m,int col,int x){
    for(auto i:adj[x]){
        if(color[i]==col){
            return false;
        }
    }
    return true;
}
bool fun(int x,vector<int>adj[],int n,int m,vector<int>color){
    if(x==n){
        return true;
    }
    for(int i=0;i<m;i++){
        if(check(color,adj,n,m,i,x)){
            color[x]=i;
            if(fun(x+1,adj,n,m,color)){
                return true;
            }
            color[x]=-1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==true){
                adj[i].push_back(j);
            }
        }
    }
    vector<int>color(n,-1);
    return fun(0,adj,n,m,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends