class Solution {
public:
    void dfs(vector<vector<char>>& arr,int i,int j){
        if(i<0 or j<0 or i>=arr.size() or j>=arr[0].size() or arr[i][j]!='O') return;
        arr[i][j]='#';
        dfs(arr,i+1,j);
        dfs(arr,i-1,j);
        dfs(arr,i,j+1);
        dfs(arr,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
    int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or i==n-1 or j==0 or j==m-1){
                    dfs(board,i,j);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};