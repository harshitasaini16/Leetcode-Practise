// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a,Item b)
   {
       double r1 = (double)a.value / (double)a.weight;
       double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
   }
    double fun(int i,int w,Item arr[],int n){
        if(i==n || w==0){
            return 0;
        }
        if(arr[i].weight<=w){
            return arr[i].value+fun(i+1,w-arr[i].weight,arr,n);
        }
        return ((double)arr[i].value/(double)arr[i].weight)*(double)w;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        return fun(0,w,arr,n);
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends