class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
            priority_queue<int>pq;
            int i;
            for(i=0; i<h.size()-1; i++){
                    if(h[i]>=h[i+1]){
                            continue;
                    }
                    int diff = h[i+1]-h[i];
                    if(b>=diff){
                            b = b-diff;
                            pq.push(diff);
                    }else if(l>0){
                            if(!pq.empty()){
                                    int past = pq.top();
                                    if(past>diff){
                                            b = b + past;
                                            pq.pop();
                                            pq.push(diff);
                                            b = b - diff;
                                    }
                            }
                            l--;
                    }else{
                            break;
                    }
            }
            return i;
    }
};