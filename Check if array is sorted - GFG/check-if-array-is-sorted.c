// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
#include<stdbool.h>


 // } Driver Code Ends
//User function Template for C

bool arraySortedOrNot(int arr[], int n) {

    //code here
     for(int i =0;i<n-1;i++){
       if(arr[i]>arr[i+1]){
           return false;
       }
   }
   return true;
    
    
}

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        bool ans = arraySortedOrNot(arr, n);
        printf("%d\n", ans);

    }
    return 0;
}  // } Driver Code Ends