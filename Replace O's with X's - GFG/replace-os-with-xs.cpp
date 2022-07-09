// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    void f(int x,int y, vector<vector<char>>&mat){
        if(x<0 || y<0 || x>=mat.size() || y>=mat[0].size() || mat[x][y]!='O'){
            return;
        }
        mat[x][y]='x';
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            f(xx,yy,mat);
        }
    }
    void fun(int x,int y, vector<vector<char>>&mat){
        if(x<0 || y<0 || x>=mat.size() || y>=mat[0].size() || mat[x][y]!='O'){
            return;
        }
        mat[x][y]='X';
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            fun(xx,yy,mat);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i=0;i<n;i++){
            f(i,0,mat);
            f(i,m-1,mat);
        }
        for(int j=0;j<m;j++){
            f(0,j,mat);
            f(n-1,j,mat);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O'){
                    fun(i,j,mat);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='x'){
                    mat[i][j]='O';
                }
            }
        }
        return mat;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends