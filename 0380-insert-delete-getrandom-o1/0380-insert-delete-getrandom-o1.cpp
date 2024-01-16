class RandomizedSet {
public:
    map<int,int>mp;
    vector<int>ans;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
                ans.push_back(val);
                mp[val]=ans.size()-1;
        }
        else return false;
        return true;
    }
    
    bool remove(int val) {
            if(mp.find(val)!=mp.end()){
                    mp[ans.back()]=mp[val];
                    swap(ans.back(),ans[mp[val]]);
                    ans.pop_back();
                    mp.erase(val);
            }
        else return false;
        return true;
    }
    
    int getRandom() {
        return ans[rand()%mp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */