// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
         vector<int> result;
       int temp,c=0;
        for(int i=0;i<n;i++){
            arr[arr[i]%n]=arr[arr[i]%n]+n;
        }
        for(int i=0;i<n;i++){
            temp=arr[i]/n;
            if(temp>1){
                result.push_back(i);
                c++;
            }
        }
        for(int i=0;i<n;i++)
       {
           arr[i]=arr[i]%n;
           
       }
       if(c>0)
       return result;
       else 
       {result.push_back(-1);
       return result;

       }
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends