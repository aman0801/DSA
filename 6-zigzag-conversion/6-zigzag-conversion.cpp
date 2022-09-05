class Solution {
public:
    string convert(string s, int r) {
        int n=s.size();
        if(r==1){
            return s;
        }
        vector<vector<char>>arr(r,vector(n,'0'));
        int limit=r-1;
        int i=0,j=0;
        int k=0;
        int key1=1;
        int key2=0;
        int count=0;
        while(k<n){
            if(i==-1){key1=1;i=1;}
            if(i==r){key1=0;i=r-2;}
            cout<<i<<" "<<j<<" "<<s[k]<<endl;
            arr[i][j]=s[k];
            if(key2){j++;}
            if(key1){i++;}else{i--;}
            if(i==r){key2=1;j++;}
            if(i==-1){key2=0;}
            k++;
        }
        string ans="";
        for(int i=0;i<r;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]!='0'){
                    ans+=arr[i][j];
                }
            }
        }
        return ans;
    }
};