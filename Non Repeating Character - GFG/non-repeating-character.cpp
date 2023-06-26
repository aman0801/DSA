//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
{
   // Your code here
   queue<char> q;
   unordered_map<char, int> frequency;

   for (char c : S) {
       frequency[c]++;
       if (frequency[c] == 1) {
           q.push(c);
       } else {
           while (!q.empty() && frequency[q.front()] > 1) {
               q.pop();
           }
       }
   }

   return q.empty() ? '$' : q.front();
}


};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends