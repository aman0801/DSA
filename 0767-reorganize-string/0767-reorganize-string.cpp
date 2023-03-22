class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>mp;
        // vector<char>a(s.size());
        string sol = s;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        int max = 0;
        char maxe = s[0];
        for(auto i:mp){
            if(max < i.second){
                max = i.second;
                maxe =i.first;
            }
        }
        if((max*2)-1> s.length()){
            return "";
        }
        int i=0;
        while(mp[maxe]>0){
            // a.push_back(i);
            s[i] = maxe;
            i = i+2;
            mp[maxe]--;
        }
        
        for(auto j:mp){
            while(j.second > 0){
                if(i>=s.size())
                    i=1;
                s[i] = j.first;
                // a.push_back(j.first);
                j.second--;
                i = i+2;
            }
        }
        // for(int i=0; i<a.size(); i++){
        //     if(a[i] == a[i+1]){
        //         return "";
        //     }
        // }
        // string ans;
        // for (int j = 0; j < a.size(); i++) {
        //      ans = ans + a[j];
        //     }
        return s;
    }
};