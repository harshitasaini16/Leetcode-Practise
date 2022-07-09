// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    string exercise(int n, int m, vector<vector<int>> a, int s, int d, int X){
        // code here
        vector<vector<int>>adj[n+1];
        for(int i=0;i<m;i++){
            int x=a[i][0];
            int y=a[i][1];
            int z=a[i][2];
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,s});
        vector<int>dist(n,INT_MAX);
        dist[s]=0;
        while(!q.empty()){
            int x=q.top().first;
            int y=q.top().second;
            if(y==d){
                if(dist[d]<=X){
            return "Neeman's Cotton Classics";
        }
        return "Neeman's Wool Joggers";
            }
            q.pop();
            for(auto i:adj[y]){
                if(x+i[1]<dist[i[0]]){
                    dist[i[0]]=x+i[1];
                    q.push({dist[i[0]],i[0]});
                }
            }
        }
        return "";
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M, src, dest, X;
        cin >> N >> M >> src >> dest >> X;
        vector<vector<int>> A(M, vector<int> (3, 0));
        for(int i = 0; i < M; i++){
            cin >> A[i][0] >> A[i][1] >> A[i][2];
        }
        Solution obj;
        cout << obj.exercise(N, M, A, src, dest, X) << "\n";
    }
}
  // } Driver Code Ends