class Solution {
public:
    int maxOnesIII(string& S, char& c, int& k) {
       int s = 0, e = 0, t = 0, ans = 0, n = S.length();
       while(e < n) {
           while(e<n and (S[e] == c or t < k)) {
               if(S[e] != c) t++;
               e++;
           }
           
           ans = max(ans, e-s);
           while(s<e and S[s] == c) s++;
           s++;
           t--;
       }
      return ans;  
    }
    
    int characterReplacement(string& s, int k) {
      int chrCount[26] = {0};
      int ans = 0;  
      for(char& c : s) {
          if(!chrCount[c-'A']) {
              ans = max(ans, maxOnesIII(s, c, k));
          } 
          chrCount[c-'A'] = 1;
      }
      return ans;   
    }
};