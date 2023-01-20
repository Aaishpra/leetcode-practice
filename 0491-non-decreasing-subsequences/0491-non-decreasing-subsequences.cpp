class Solution {
public:

  set<vector<int>> res;
    void solve(int idx,vector<int> &ip,vector<int> &op){ 
        if(idx>=ip.size()){
            if(op.size()>=2){
            res.insert(op);
            }
            return;
        }
      
    if(!op.size() or op.back()<=ip[idx]){
        op.push_back(ip[idx]);
        solve(idx+1,ip,op);
        op.pop_back();
        }
      
        
        solve(idx+1,ip,op);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> op;
      
      //  op.push_back(nums[0]);
        solve(0,nums,op);
        return vector(res.begin(),res.end());
    }
};