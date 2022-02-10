class Solution {
public:
    bool validPalindrome(string s) {
     int count=0;
        int lo=0,hi=s.size()-1;
        while(lo<hi){
            if(s[lo]==s[hi]){
            
                lo++; 
                hi--;
            }
        else lo++,count++;
            
        }
        lo=0,hi=s.size()-1;
        int count1=0;
        while(lo<=hi){
            if(s[lo]==s[hi]){
    lo++,hi--;
            }
            else hi--, count1++;
        }
        
      //  while()
        if(count==0 || count1==0 or count==1 or count1==1)return true;
        return false;
    }
};