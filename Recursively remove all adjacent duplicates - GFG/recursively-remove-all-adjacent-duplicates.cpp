//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
        string temp;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[i+1]&&s[i]!=s[i-1]){
               temp+=s[i];
            }
        }
        if(s.size()==temp.size()){
            return temp;
        }
        return rremove(temp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends