class StockSpanner {
public:
    vector<int>ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        for(int i=ans.size()-1; i>=0; i--){
            if(price>=ans[i]){
                count++;
            }else{
                break;
            }
        }
        ans.push_back(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */