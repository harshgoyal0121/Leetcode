//{ Driver Code Starts
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
    public:
    void merge(int arr[], int l, int m, int h) {
        // Your code here
        int n = m-l+1;
        int n2 = h-m;
        int a1[n], a2[n2];
        for(int i =0; i<n; i++)
            a1[i]=arr[i+l];
        for(int i =0; i<n2; i++)
            a2[i]=arr[i+m+1];
        
        int i=0, j=0, k=l;
        while(i<n && j<n2){
            if(a1[i]<=a2[j])
                arr[k++]=a1[i++];
            else
                arr[k++]=a2[j++];
        }
        for(; i<n; i++)
            arr[k++]=a1[i];
        for(; j<n2; j++)
            arr[k++]=a2[j];
        
    }
    public:
    void mergeSort(int arr[], int l, int h)
    {
        //code here
        if(l<h){
            int mid = (l+h)/2;
            
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, h);
            
            merge(arr, l, mid, h);
        }
    }
};

//{ Driver Code Starts.


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
}
// } Driver Code Ends