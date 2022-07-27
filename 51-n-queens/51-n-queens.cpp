class Solution {
public:
    vector<vector<string>> res;
    bool isValid(vector<string>& board,int row,int col){
        int n=board.size();
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q')return false;
            if(row-i>=0 and col-i>=0 and board[row-i][col-i]=='Q')return false;
            if(row-i>=0 and col+i<n and board[row-i][col+i]=='Q')return false;
            if(row+i<n and col-i>=0 and board[row+i][col-i]=='Q')return false;
            if(row+i<n and col+i<n and board[row+i][col+i]=='Q')return false;
        }
        return true;
    }
    void solve(vector<string>& board,int row){
        if(row==board.size()){
            res.push_back(board);
            return;
        }
        for(int col=0;col<board.size();col++){
            if(isValid(board,row,col)){
                board[row][col]='Q';
                solve(board,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        solve(temp,0);
        return res;
    }
};