class Solution {
public:
        
    vector<int> left(vector<int>& arr){
            vector<int>result(arr.size());
            stack<int>st;
            
            for(int i=0; i<arr.size(); i++){
                    if(st.empty()){
                            result[i] = -1;
                    }else{
                            while(!st.empty() && arr[st.top()] >= arr[i]){
                                    st.pop();
                            }
                            if(st.empty()){
                                    result[i] = -1;
                            }else{
                                    result[i] = st.top();
                            }
                    }
                    st.push(i);
            }
            return result;
    } 
        
    vector<int> right(vector<int>& arr){
            vector<int>result(arr.size());
            stack<int>st;
            
            for(int i=arr.size()-1; i>=0; i--){
                    if(st.empty()){
                            result[i] = arr.size();
                    }else{
                            while(!st.empty() && arr[st.top()] > arr[i]){
                                    st.pop();
                            }
                            if(st.empty()){
                                    result[i] = arr.size();
                            }else{
                                    result[i] = st.top();
                            }
                    }
                    st.push(i);
            }
            return result;
    }     
        
    int sumSubarrayMins(vector<int>& arr) {
            vector<int>NSL = left(arr);
            vector<int>NSR = right(arr);
            
            long long sum = 0;
            int m = 1e9+7;
            
            for(int i=0; i<arr.size(); i++){
                    long long ls = i - NSL[i];
                    long long rs = NSR[i] - i;
                    
                    long long ways = ls*rs;
                    long long temp = ways*arr[i];
                    
                    sum = (sum+temp)%m;
            }
            return sum;
    }
};