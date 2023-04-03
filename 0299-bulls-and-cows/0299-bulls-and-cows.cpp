class Solution {
public:
    string getHint(string secret, string guess) {
    
        int count = 0;
        int count_1 = 0;
        unordered_map<char, char>mp;
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                count++;
            }else{
                mp[secret[i]]++;
            }
        }
        
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]!=guess[i] && mp.find(guess[i])!=mp.end())
            {
                count_1++;
                mp[guess[i]]--;
                if(mp[guess[i]]==0)
                    mp.erase(guess[i]);
            }
        }
        
        string ans = "";
        ans = ans + to_string(count);
        ans = ans + 'A';
        ans = ans + to_string(count_1);
        ans = ans + 'B';
        
        return ans;
    }
};