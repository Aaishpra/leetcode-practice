class Solution {
public:
    vector<vector<int>> res;
    void solve(int ind,int k,vector<int>& nums,vector<int> temp,int target){
        if(temp.size()==k and target==0){
            res.push_back(temp);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(i+1,k,nums,temp,target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=0;i<9;i++){
            nums.push_back(i+1);
        }
        vector<int> temp;
        solve(0,k,nums,temp,n);
        return res;
    }
};