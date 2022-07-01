class Solution {
public:
void dfs(vector<vector<char>>& board,int i,int j){
if(i<0 and i>board.size() and j<0 and j>board[0].size() and board[i][j]!='O')
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
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(board[i][j]=='O') dfs(board,i,j);
}
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(board[i][j]=='O')
board[i][j]='X';
else if(board[i][j]=='#')