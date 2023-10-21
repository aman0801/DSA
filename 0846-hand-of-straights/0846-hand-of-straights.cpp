class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize !=0)
            return false;
        map<int,int>mp;
        for(int i=0;i<hand.size();i++)
        {
            mp[hand[i]]+=1;
        }

        priority_queue<int>maxh;
        for(auto i:mp)
        {
            maxh.push(i.first);
        }
        
        while(! maxh.empty())
        {
            int x=maxh.top();
            for(int i = x ; i> x-groupSize ;i--)
            {
                if(mp.find(i) == mp.end())
                    return false;
                mp[i]--;
                if(mp[i]==0)
                {
                    maxh.pop();
                    mp.erase(i);
                }       
            }
        }
        return true;
    }
};