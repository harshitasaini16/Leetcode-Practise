// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool fun(int x,vector<int>adj[],map<int,int>&m,int n){
        m[x]++;
        if(m.size()==n){
            return true;
        }
        for(auto i:adj[x]){
            if(m[i]==0){
                if(fun(i,adj,m,n)){
                    return true;
                }
            }
        }
        m[x]--;
        if(m[x]==0){
            m.erase(x);
        }
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int>adj[N+1];
        for(int i=0;i<Edges.size();i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        map<int,int>m;
        for(int i=1;i<=N;i++){
            if(fun(i,adj,m,N)){
                return true;
            }
        }
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends