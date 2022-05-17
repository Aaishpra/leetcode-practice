// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> Reverse(stack<int> st){
        //int x;
        vector<int> ans;
        if(st.empty()==true){
            return ans;
        }
        int x=st.top();
        st.pop();
        
        Reverse(st);
        
        st.push(x);
        while(!st.empty()){
            x=st.top();
            st.pop();
            ans.push_back(x);
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends