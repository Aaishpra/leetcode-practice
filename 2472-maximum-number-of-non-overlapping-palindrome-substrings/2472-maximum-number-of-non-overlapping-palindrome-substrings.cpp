class Solution {
public:
    bool isPalindrome(string s,int l,int r){
        while(l<r){
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int cnt=0;
       
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(j-i+1>k+1) break;
                else if(j-i+1>=k and isPalindrome(s,i,j))
                {
                    cnt++;
                    i=j;
                    break;
                }
            }
        }
        return cnt;
    }
};