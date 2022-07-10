// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void fun(int x,stack<int>&st,map<int,int>&vis,vector<vector<int>>adj){
        vis[x]++;
        for(auto i:adj[x]){
            if(vis[i]==0){
                fun(i,st,vis,adj);
            }
        }
        st.push(x);
    }
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<vector<int>>adj(k);
        for(int i=0;i<n-1;i++){
            string a=dict[i];
            string b=dict[i+1];
            for(int j=0;j<a.length() && j<b.length();j++){
                if(a[j]!=b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        map<int,int>vis;
        stack<int>st;
        for(int i=0;i<k;i++){
            if(vis[i]==0){
                fun(i,st,vis,adj);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top()+'a');
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends