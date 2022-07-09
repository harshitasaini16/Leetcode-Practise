// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
    bool fun(int i,int x,int y,vector<vector<char>>& board, string word){
        if(i>=word.length()){
            return true;
        }
        if(x>=board.size() || y>=board[0].size() || x<0 || y<0 || board[x][y]!=word[i]){
            return false;
        }
        char c=board[x][y];
        board[x][y]='-';
        for(auto d=0;d<4;d++){
            int xx=x+dx[d];
            int yy=y+dy[d];
            if(fun(i+1,xx,yy,board,word)){
                return true;
            }
        }
        board[x][y]=c;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(fun(0,i,j,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends