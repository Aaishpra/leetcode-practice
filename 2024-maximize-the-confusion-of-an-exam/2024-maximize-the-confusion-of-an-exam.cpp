class Solution {
public:
    int solve(string s, int k,char ans){
        int i=0,j=0;
        int count=0,maxlen=0;
        while(j<s.length()){
            if(s[j]==ans) count++;
            if(count<=k){
                maxlen=max(maxlen,j-i+1);
                j++;
            }
          else  if(count>k){
                while(count>k){
                    if(s[i]==ans)
                    {
                        count--;}
                    i++;
                }
            j++;}
        }
        return maxlen;
    }
    int maxConsecutiveAnswers(string s, int k) {
        
        return max(solve(s,k,'F'),solve(s,k,'T'));
    }
};