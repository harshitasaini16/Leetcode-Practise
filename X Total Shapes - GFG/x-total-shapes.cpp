// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int ans=0;
        vector<pair<int,int>>v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='X'){
                    v.push_back({i,j});
                }
            }
        }
        // int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<v.size();i++){
            int x=v[i].first;
            int y=v[i].second;
            if(grid[x][y]=='X'){
                queue<pair<int,int>>q;
                ans++;
                q.push({x,y});
                grid[x][y]='O';
                while(!q.empty()){
                    int xx=q.front().first;
                    int yy=q.front().second;
                    q.pop();
                    for(int j=0;j<4;j++){
                        int dxx=xx+dx[j];
                        int dyy=yy+dy[j];
                        if(dxx>=0 && dyy>=0 && dxx<n && dyy<m && grid[dxx][dyy]=='X'){
                            q.push({dxx,dyy});
                            grid[dxx][dyy]='O';
                        }
                    }
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends