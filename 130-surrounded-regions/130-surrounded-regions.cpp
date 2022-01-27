class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!='O')
            return;
        board[i][j]='#';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        if(n==0)return;
        //moving over first and last column and rows
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or j==m-1 or i==n-1){
                if(board[i][j]=='O') dfs(board,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
        
    }
};
