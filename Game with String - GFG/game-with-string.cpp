//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int> mp;
        int mx=INT_MIN;
        for(char c:s){
            mp[c]++;
            mx=max(mp[c],mx);
        }
        priority_queue<int> pq;
        for(auto m:mp){
            pq.push(m.second);
        }
        while(k){
            int tp=pq.top();
            pq.pop();
            pq.push(tp-1);
          
            k--;
        }
        int res=0;
        while(!pq.empty()){
            res+=pq.top()*pq.top();
            pq.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends