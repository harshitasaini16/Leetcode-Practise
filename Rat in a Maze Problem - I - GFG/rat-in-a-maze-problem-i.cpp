// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void fun(vector<vector<int>>arr,int i,int j,string s,int n){
        if(i<0 or j<0 || i>=n or j>=n or arr[i][j]==0){
            return;
        }
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        arr[i][j]=0;
        fun(arr,i+1,j,s+"D",n);
        fun(arr,i-1,j,s+"U",n);
        fun(arr,i,j+1,s+"R",n);
        fun(arr,i,j-1,s+"L",n);
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        ans.clear();
        fun(m,0,0,"",n);
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