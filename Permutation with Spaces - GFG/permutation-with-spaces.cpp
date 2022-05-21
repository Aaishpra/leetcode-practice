// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
vector<string> ans;    
    void solve(string ip,string op){
        if(ip.length()==0){
            ans.push_back(op);
            return;
        }
        string op1=op;
        string op2=op;
        op1.push_back(' ');
        op1.push_back(ip[0]);
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        
        solve(ip,op1);
        solve(ip,op2);
        return;
    }
    vector<string> permutation(string ip){
        // Code Here
        string op="";
        op.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op);
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends