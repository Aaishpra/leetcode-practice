class Solution {
public:
    vector<vector<int>> res;
    void solve(int start,int end,vector<int>& temp,int k){
        if(temp.size()==k){
            res.push_back(temp);
        }
        for(int i=start;i<=end;i++){
            temp.push_back(i);
            solve(i+1,end,temp,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,n,temp,k);
        return res;
    }
};