// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int minStepToReachTarget(vector<int>&s,vector<int>&t,int n){
	    queue<pair<int,int>>q;
	    q.push({s[0],s[1]});
	    vector<vector<int>>m(n+1,vector<int>(n+1,0));
	    m[s[0]][s[1]]++;
	    int z=0;
	    while(!q.empty()){
	        int size=q.size();
	        while(size--){
	            int x=q.front().first;
	            int y=q.front().second;
	            if(x==t[0] && y==t[1]){
	                return z;
	            }
	            q.pop();
	            for(int i=0;i<8;i++){
	                int xx=x+dx[i];
	                int yy=y+dy[i];
	                if(xx>=1 && yy>=1 && xx<=n && yy<=n && m[xx][yy]==0){
	                    q.push({xx,yy});
	                    m[xx][yy]++;
	                }
	            }
	        }
	        z++;
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends