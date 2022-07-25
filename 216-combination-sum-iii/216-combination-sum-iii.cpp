class Solution {
public:
    vector<vector<int>> res;
    void solve(int ind,int k,vector<int> temp,int target){
        if(temp.size()==k and target==0){
            res.push_back(temp);
            return;
        }
        
        for(int i=ind;i<9;i++){
            temp.push_back(i+1);
            solve(i+1,k,temp,target-i-1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(0,k,temp,n);
        return res;
    }
};