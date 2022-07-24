class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,int n,vector<int> temp,vector<int>& nums){
        if(i==n){
            res.push_back(temp);
            return;
        }
        
        solve(i+1,n,temp,nums);
        temp.push_back(nums[i]);
        solve(i+1,n,temp,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0,nums.size(),temp,nums);
        return res;
    }
};