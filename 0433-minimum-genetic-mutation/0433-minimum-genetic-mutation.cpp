class Solution {
public:
    bool isValid(string& s, string& target)
    {
        int changedCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != target[i])  changedCount++; 
        }
        if (changedCount == 1) return true; //if ony one char is changed then "MUTATION IS VALID"
        return false;  //changedCount == 0 or changedCount > 1 => "MUTATION IS INVALID"
    }
    int minMutation(string start, string end, vector<string>& bank) 
    {
        
        bank.push_back(start); //start is also a valid string mutation
        int n = bank.size();
        
        queue<string>q;
        vector<bool>visited(n, false); //to keep a track of visited strings from bank
        visited[n - 1] = true; //marking index of "start" string as visited
        q.push(start);
        
        int stepCount = 0;
        while(!q.empty())
        {
            int size = q.size(); 
            while(size--) //iterating level wise to keep a track of steps(levels of bfs)
            {
                string curr = q.front();
                q.pop();
                if (curr == end) return stepCount; //target found 
                for (int i = 0; i < n; i++)
                {
                    bool valid = isValid(curr, bank[i]);
                    if (!valid || visited[i]) continue;

                    visited[i] = true;
                    q.push(bank[i]);
                }
            }
            stepCount++; //after each level stepCount is increased by 1
        }
        return -1;
    }
};