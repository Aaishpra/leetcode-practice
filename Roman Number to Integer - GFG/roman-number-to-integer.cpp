//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000; 
         long long int ans=mp[str[0]];
              int p=0;
              for(int i=1;i<str.size();i++){
              int u=mp[str[i-1]];
                  if(u<mp[str[i]]){
                      ans+=mp[str[i]];
                      ans-=2*u;
                      continue;
                  }
                  else{
                  ans+=mp[str[i]];
                  }
              }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends