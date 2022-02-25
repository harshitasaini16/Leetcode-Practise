// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    char d[4]={'U','L','D','R'};
    vector<string>ans;
    void fun(vector<vector<int>>mat,int n,string s,int x,int y){
        if(x<0 || y<0 || x>=n || y>=n || mat[x][y]==0){
            return;
        }
        if(x==n-1 && y==n-1){
            ans.push_back(s);
            return;
        }
        mat[x][y]=0;
        for(int i=0;i<4;i++){
            fun(mat,n,s+d[i],x+dx[i],y+dy[i]);
        }
    }
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        // Your code goes here
        string s="";
        fun(mat,n,s,0,0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends