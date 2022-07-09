// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool fun(int x,map<int,int>&vis1,map<int,int>&vis2,vector<int>adj[]){
        vis1[x]++;
        vis2[x]++;
        for(auto i:adj[x]){
            if(vis1[i]==0){
                if(fun(i,vis1,vis2,adj)){
                    return true;
                }
            }
            else if(vis2[i]>0){
                return true;
            }
        }
        vis2[x]=0;
        return false;
    }
		bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>adj[N];
	    map<int,int>vis1,vis2;
	    for(int i=0;i<pre.size();i++){
	        adj[pre[i].second].push_back(pre[i].first);
	    }
	    for(int i=0;i<N;i++){
	        if(vis1[i]==0){
	            if(fun(i,vis1,vis2,adj)){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends