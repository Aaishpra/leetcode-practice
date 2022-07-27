class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,int n,vector<int> &nums,vector<int> temp){
        if(i==n){
            res.push_back(temp);
            return;
        }
        solve(i+1,n,nums,temp);
        temp.push_back(nums[i]);
        solve(i+1,n,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        solve(0,n,nums,temp);
        return res;   
    }
};