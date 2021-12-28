vector<vector<string>> ans;
int n;
string s;
bool isPalin(int i,int j)// check for palindrome
{
    while(i<j)
    {
        if(s[i]!=s[j])return 0;
        i++;j--;
    }
    return 1;
}
void palinParti(vector<string>& cur,int start)
{
    if(start==n){ans.push_back(cur);return;} // base case
    
        for(int i=start;i<n;i++)
        {
            if(isPalin(start,i))
            {
                cur.push_back(s.substr(start,i-start+1));// push the current substring on to the vector.
                
                palinParti(cur,i+1); // typical MCM(Matrix-Chain-Multiplication) based approach
                
                cur.pop_back(); // back-track for next substring from (start to i)
            }
        }
}
class Solution {
public:
    vector<vector<string>> partition(string S)
    {s=S;
      n=s.length();
      ans.clear();
      vector<string> cur;
     
     palinParti(cur,0);
     
     return ans;
    }};