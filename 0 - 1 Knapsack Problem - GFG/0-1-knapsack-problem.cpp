// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    map<pair<int,int>,int>dp;
    int f(int n, int wt[], int val[], int w){
        if(w==0 || n==0){
            return 0;
        }
        if(dp.find({n,w})!=dp.end()){
            return dp[{n,w}];
        }
        if(w>=wt[n-1]){
            return dp[{n,w}]=max(f(n-1,wt,val,w),val[n-1]+f(n-1,wt,val,w-wt[n-1]));
        }
        else{
            return dp[{n,w}]=f(n-1,wt,val,w);
        }
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       dp.clear();
       return f(n,wt,val,w);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends