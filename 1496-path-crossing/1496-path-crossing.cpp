class Solution {
public:
    bool isPathCrossing(string path) {
            pair<int, int>pr;
            pr.first = 0;
            pr.second = 0;
            
            set<pair<int, int>>st;
            
            for(int i=0; i<path.length(); i++){
                  if(st.find(pr) != st.end()){
                          return true;
                  }else if(st.find(pr) == st.end()){
                          st.insert(pr);
                  }
                    
                  char temp = path[i];
                    if(temp == 'N'){
                            pr.first = pr.first - 1;
                    }else if(temp == 'S'){
                            pr.first = pr.first + 1;
                    }else if(temp == 'E'){
                            pr.second = pr.second + 1;
                    }else{
                            pr.second = pr.second - 1;
                    }
            }
            
            if(st.find(pr) != st.end()){
                    return true;
            }else if(st.find(pr) == st.end()){
                    st.insert(pr);
            }
            return false;
    }
};