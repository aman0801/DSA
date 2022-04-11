// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    int one=0,two=0,three=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            one++;
        }else if(a[i]==1){
            two++;
        }else{
            three++;
        }
    }
     for(int i=0;i<one;i++)
        a[i]=0;
        
        for(int i=one;i<one+two;i++)
        a[i]=1;
        
        for(int i=one+two;i<one+two+three;i++)
        a[i]=2;
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends