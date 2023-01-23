class Solution {
public:
    vector<vector<int>> res;
    void solve(int ind,int n,vector<int> temp,vector<int>& nums,int target){
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            if(nums[i]>target) continue;
            if(i>ind and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,temp,nums,target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int> temp;
        sort(c.begin(),c.end());
        solve(0,c.size(),temp,c,target);
        return res;
    }
};