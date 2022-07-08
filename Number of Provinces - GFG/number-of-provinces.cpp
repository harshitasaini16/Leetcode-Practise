// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void fun(int x,vector<int>adj[],map<int,int>&m){
      m[x]++;
      for(auto i:adj[x]){
          if(m[i]==0){
              fun(i,adj,m);
          }
      }
  }
    int numProvinces(vector<vector<int>> ad, int V) {
        // code here
        vector<int>adj[V+1];
        for(int i=0;i<ad.size();i++){
            for(int j=0;j<ad[i].size();j++){
                if(ad[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        map<int,int>m;
        for(int i=0;i<V;i++){
            if(m[i]==0){
                fun(i,adj,m);
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends