//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[], long long N, long long s, long long m, long long e){
        long long int count = 0;
        long long k = 0;
        long long l = s, r = m+1, size = e-s+1;
        
         vector<long long>sorted(size);
        while(l <= m and r <= e)
        {
            if(arr[l] <=arr[r]){
                sorted[k++] =arr[l++];
            }
            else
            {
                sorted[k++] =arr[r++];
                count = count + (m-l+1); 
            }
        }
        
        while(l <= m)
            sorted[k++] = arr[l++];
    
        while(r <= e)
            sorted[k++] =arr[r++];
    
        for(k = 0 ; k < size ; k++)
        arr[k+s] = sorted[k];
        return count;
        
    }
    
    long long ms(long long arr[], long long N, long long s, long long e){
        if(s>=e){
            return 0;
        }
        
        long long m = (s+e)/2;
        long long count = 0;
        count = count + ms(arr, N, s, m);
        count = count + ms(arr, N, m+1, e);
        count = count + merge(arr, N, s, m, e);
        
        return count;
        
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return ms(arr, N, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends