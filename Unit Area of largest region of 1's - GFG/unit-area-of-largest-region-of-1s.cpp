// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dx[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int dy[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    int ans=0;
                    grid[i][j]=0;
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        ans++;
                        for(int j=0;j<8;j++){
                            int xx=x+dx[j];
                            int yy=y+dy[j];
                            if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]==1){
                                grid[xx][yy]=0;
                                q.push({xx,yy});
                            }
                        }
                    }
                    mx=max(mx,ans);
                }
            }
        }
        return mx;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends