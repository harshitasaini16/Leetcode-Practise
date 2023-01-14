//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[501];
    int fun(int x,vector<int>nums, int k){
        if(x>=nums.size()){
            return 0;
        }
        int f=0;
        for(int i=x;i<nums.size();i++){
            f+=nums[i];
            f++;
        }
        f--;
        if(f<=k){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int i=x;
        int g=0;
        int ans=INT_MAX;
        while(i<nums.size() && g+nums[i]<=k){
            g+=nums[i];
            i++;
            int temp=(k-g)*(k-g);
            ans=min(ans,temp+fun(i,nums,k));
            g++;
        }
        return dp[x]=ans;
    }
    int solveWordWrap(vector<int>nums, int k){ 
        // Code here
        memset(dp,-1,sizeof(dp));
        return fun(0,nums,k);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends