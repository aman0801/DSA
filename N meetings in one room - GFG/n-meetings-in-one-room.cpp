//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(pair<int, int>a, pair<int, int>b){
        return a.second<b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>>arr;
        for(int i=0; i<n; i++){
            pair<int, int>temp = make_pair(start[i], end[i]);
            arr.push_back(temp);
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        int count = 1;
        int arrEnd = arr[0].second;
        
        for(int i=1; i<n; i++){
            if(arrEnd < arr[i].first){
                arrEnd = arr[i].second;
                count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends