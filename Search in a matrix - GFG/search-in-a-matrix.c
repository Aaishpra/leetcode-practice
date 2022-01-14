// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int matSearch (int n, int m, int matrix[][m], int x)
{
    int i=0;
    int j=m-1;
    // if (n == 0)
    //     return -1;
  
    // int smallest = matrix[0][0], largest = matrix[n - 1][n - 1];
    // if (x < smallest || x > largest)
    //     return -1;
  
    while (i < n && j >= 0){
        if(matrix[i][j]==x){
            return 1;
        }
        else if(matrix[i][j]>x){
            j--;
        }
        else if(matrix[i][j]<x){
            i++;
        }
    }
    return 0;
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--)
	{
        int n, m;
		scanf("%d", &n);
		scanf("%d", &m);
		int matrix[n][m];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		   
		int x;
		scanf("%d", &x);
		
        int result = matSearch (n, m, matrix, x);
        printf("%d", result);
		printf("\n");
    }
    return 0;
}
  // } Driver Code Ends