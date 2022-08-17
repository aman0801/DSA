class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        int carry=0;
        string ans="";
        
        while(n1>=0 or n2>=0 or carry){
            int sum=0;
            if(n1>=0){
                sum=sum+(num1[n1]-'0');
                n1--;
            }
            if(n2>=0){
                sum=sum+(num2[n2]-'0');
                n2--;
            }
            sum=sum+carry;
            carry=sum/10;
            sum=sum%10;
            
            ans=ans+to_string(sum);
            
           
        } 
                   reverse(ans.begin(),ans.end());
        
                    return ans;

        
        // int i = 0, j = 0;
        // int k =0;
        // long long sum1=0,sum2=0;
        // string ans;
        // while(i<n1){
        //       sum1=(sum1*10)+(num1[i]-'0');
        //     i++;
        // }
        // while(j<n2){
        //       sum2=(sum2*10)+(num2[j]-'0');
        //     j++;
        // }
        // long long sum3=sum1+sum2;
        // cout<<sum1<<" "<<sum2<<endl;
        // string a= to_string(sum3);
        
        
    }
    // return ans;
};