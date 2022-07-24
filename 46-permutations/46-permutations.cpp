class Solution {
public:
    vector<vector<int>> res;
    void solve(int pos,int n,vector<int>& curr){
        if(pos==n-1){
            res.push_back(curr);
            return;
        }
        
        for(int i=pos;i<n;i++){
            swap(curr[pos],curr[i]);
            solve(pos+1,n,curr);
            swap(curr[pos],curr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums.size(),nums);
        return res;
    }
};