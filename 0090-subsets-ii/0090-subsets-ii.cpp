class Solution {
public:
    set<vector<int>> res;
    void solve(int ind,int n,vector<int>& nums,vector<int> temp){
        res.insert(temp);
        for(int i=ind;i<n;i++){
         //   if(i>ind and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(0,nums.size(),nums,temp);
        return vector(res.begin(),res.end());
    }
};