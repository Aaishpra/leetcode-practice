// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        bool t[n+1][sum+1];
        
        for (int i = 0; i <= n; i++) { // itereate as long it is less then length of the array
		for (int j = 0; j <= sum; j++) { 
			if (i == 0)// when array(i) is empty than there is no meaning of sum of elements so return false
				t[i][j] = false;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return it as true;
				t[i][j] = true;
		}
	}
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
              
               // if(i==j)t[i][j]=true;
                 if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] or t[i-1][j];
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends