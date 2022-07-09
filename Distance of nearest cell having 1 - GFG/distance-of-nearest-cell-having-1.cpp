// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<int,int>>q;
	    vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        int d=ans[x][y];
	        q.pop();
	        for(int i=0;i<4;i++){
	            int xx=x+dx[i];
	            int yy=y+dy[i];
	            if(xx>=0 && yy>=0 && xx<n && yy<m && ans[xx][yy]>d+1){
	                ans[xx][yy]=d+1;
	                q.push({xx,yy});
	            }
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends