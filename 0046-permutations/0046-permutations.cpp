class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx,int n,vector<int>& nums){
        if(idx==n-1){
            res.push_back(nums);
            return;
        }
        
        for(int i=idx;i<n;i++){
            swap(nums[idx],nums[i]);
            solve(idx+1,n,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums.size(),nums);
        return res;
    }
};