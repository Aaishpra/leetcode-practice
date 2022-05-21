// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
vector<string> ans;
    void solve(int ones,int zeros,int n,string op){
        if(n==0){
            ans.push_back(op);
            return;
        }
        string op1=op;
        op1.push_back('1');
        solve(ones+1,zeros,n-1,op1);
        if(ones>zeros){
            string op2=op;
            op2.push_back('0');
            solve(ones,zeros+1,n-1,op2);
        }
        return;
    }
	vector<string> NBitBinary(int N)
	{
	    string op="";
	    solve(0,0,N,op);
	    return ans;
	    // Your code goes here
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends