// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int i=l,j=m+1,k=l;
         vector<int>v;
         while(i<=m and j<=r){
             if(arr[i]<=arr[j]){
                 v.push_back(arr[i]);
                 i++;
             }else{
                 v.push_back(arr[j]);
                 j++;
             }
         }
         while(i<=m){
            v.push_back(arr[i]);
            i++;
         }
         while(j<=r){
            v.push_back(arr[j]);
            j++;
         }
         for(i=0;i<v.size();i++){
             arr[i+k]=v[i];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            int m=l+(r-l)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends