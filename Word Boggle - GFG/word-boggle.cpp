// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    bool fun(int x,int y,vector<vector<char>>&board,string s,int i,map<pair<int,int>,int>m){
        if(i==s.length()){
            return true;
        }
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]!=s[i] || m[{x,y}]>0){
            return false;
        }
        m[{x,y}]++;
        for(int j=0;j<8;j++){
            if(fun(x+dx[j],y+dy[j],board,s,i+1,m)){
                return true;
            }
        }
        m[{x,y}]=0;
        return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& d) {
	    // Code here
	    vector<string>ans;
	    for(int k=0;k<d.size();k++){
	        bool f=false;
	        
	        for(int i=0;i<board.size();i++){
	            for(int j=0;j<board[0].size();j++){
	                if(board[i][j]==d[k][0]){
	                    map<pair<int,int>,int>vis;
	                    if(fun(i,j,board,d[k],0,vis)){
	                        f=true;
	                        break;
	                    }
	                }
	            }
	            if(f==true){
	                break;
	            }
	        }
	        if(f==true){
	            ans.push_back(d[k]);
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
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends