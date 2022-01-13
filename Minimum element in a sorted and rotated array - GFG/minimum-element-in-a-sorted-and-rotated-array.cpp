// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:

    int findMin(int nums[], int n){
    
    int start =0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        
        if(nums[mid]<nums[next] and nums[mid]<nums[prev]) return nums[mid];
        
        else if(nums[mid]>nums[end]) start=mid+1;
        else end=mid-1;
    }//complete the function here
    
        return -1;
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends