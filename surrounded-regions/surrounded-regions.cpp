class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ||grid[i][j]!='O') return;
        grid[i][j]='#';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
         
     int m = board.size();
        
      if(m == 0) return;  
        
     int n = board[0].size();
     
     //Moving over first and last column   
     for(int i=0; i<m; i++) {
         for (int j = 0; j < n; j++){
         if (i == 0 || j == 0 || i == m-1 || j == n-1){
             if(board[i][j]=='O'){
 					dfs(board, i, j);}}}}
//          if(board[i][0] == 'O')
//              dfs(board, i, 0);
//          if(board[i][n-1] == 'O')
//              dfs(board, i, n-1);
//      }
        
        
//      //Moving over first and last row   
//      for(int j=0; j<n; j++) {
//          if(board[0][j] == 'O')
//              dfs(board, 0, j);
//          if(board[m-1][j] == 'O')
//              dfs(board, m-1, j);
//      }
        
     for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
         }
    }
    
};