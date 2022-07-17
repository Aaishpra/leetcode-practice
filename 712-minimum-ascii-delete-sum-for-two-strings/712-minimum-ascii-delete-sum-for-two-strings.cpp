class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 or j==0) 
                    t[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
               // if(i==0 or j==0) t[i][j]=0;
                 if(s1[i-1]==s2[j-1]){
                     // if len 1+t[i-1][j-1]
                    t[i][j]=s1[i-1]+t[i-1][j-1];
                }
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=s1[i];
        
        for(int j=0;j<m;j++)
            sum+=s2[j];
        
         // m+n-2*lcs // for length 
         // m+n-2*lcs1//for ascii
        return sum-2*t[n][m];
    }
};