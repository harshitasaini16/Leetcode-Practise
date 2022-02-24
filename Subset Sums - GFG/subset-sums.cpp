// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
   vector<int>v;
   void fun(int i,vector<int>arr,int n,int s){
       if(i==n){
           v.push_back(s);
           return;
       }
       fun(i+1,arr,n,s);
       fun(i+1,arr,n,s+arr[i]);
   }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        v.clear();
        fun(0,arr,n,0);
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends