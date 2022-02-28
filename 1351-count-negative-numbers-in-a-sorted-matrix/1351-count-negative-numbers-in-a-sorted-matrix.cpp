class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       int count=0;
        int n=grid.size()-1;
        int i=0 ,j=grid[0].size()-1;
        while(i<=n and j>=0){
            int number=grid[i][j];
            if(number<0) 
            {
             count+=(n-i+1);
             j-=1;
            }
            else {
                i++;
            }
        }
        return count;
    }
};