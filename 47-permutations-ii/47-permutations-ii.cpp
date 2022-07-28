class Solution {
public:
    set<vector<int>> res;
    void backtrack(int pos,int n,vector<int>& nums){
        if(pos==n-1){
            res.insert(nums);
            return;
        }
        for(int i=pos;i<n;i++){
            swap(nums[pos],nums[i]);
            backtrack(pos+1,n,nums);
            swap(nums[pos],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(0,nums.size(),nums);
        vector<vector<int>> r(res.begin(),res.end());
        return r;
    }
};