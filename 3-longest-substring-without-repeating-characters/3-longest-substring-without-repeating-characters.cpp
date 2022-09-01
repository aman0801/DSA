class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int i=0,j=0,ans=0;
        
        while(j<s.size()){
            //If the character does not in the set
           //Insert the character in set and update the j counter
          //Check if the new distance is longer than the current answer
            if(set.find(s[j])==set.end()){
                set.insert(s[j++]);
                ans = max(ans,j-i);
            }else{
                //If character does exist in the set, ie. it is a repeated character, 
				//we update the left side counter i, and continue with the checking for substr
                set.erase(s[i++]);
            }
        }
        return ans;
    }
};