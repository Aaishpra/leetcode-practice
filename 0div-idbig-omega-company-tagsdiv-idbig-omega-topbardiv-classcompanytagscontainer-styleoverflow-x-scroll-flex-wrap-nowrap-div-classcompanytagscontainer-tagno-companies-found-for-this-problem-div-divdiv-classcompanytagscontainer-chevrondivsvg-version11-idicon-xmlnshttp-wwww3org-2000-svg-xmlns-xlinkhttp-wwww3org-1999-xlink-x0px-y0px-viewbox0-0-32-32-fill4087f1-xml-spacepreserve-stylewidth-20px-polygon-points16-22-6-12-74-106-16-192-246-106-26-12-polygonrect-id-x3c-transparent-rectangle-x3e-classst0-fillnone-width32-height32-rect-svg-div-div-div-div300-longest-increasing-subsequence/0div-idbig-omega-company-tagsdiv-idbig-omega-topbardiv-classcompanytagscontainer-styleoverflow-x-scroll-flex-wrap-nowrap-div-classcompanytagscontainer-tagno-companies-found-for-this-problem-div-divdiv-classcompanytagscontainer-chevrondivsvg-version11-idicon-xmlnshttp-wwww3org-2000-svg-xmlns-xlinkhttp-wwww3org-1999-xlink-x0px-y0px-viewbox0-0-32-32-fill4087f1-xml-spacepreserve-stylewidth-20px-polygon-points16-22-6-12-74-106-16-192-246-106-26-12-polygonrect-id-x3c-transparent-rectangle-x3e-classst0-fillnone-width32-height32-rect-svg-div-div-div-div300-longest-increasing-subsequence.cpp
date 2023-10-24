class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        for(int n:nums){
            if(dp.empty() or dp.back()<n) dp.push_back(n);
            else {
                auto it=lower_bound(dp.begin(),dp.end(),n);
                *it=n;
            }
        }
        return dp.size();
        // TC - O (N^2)
        // int n=nums.size();
        // vector<int> dp(n+1,1);
        // int mx=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j]){
        //             dp[i]=max(dp[i],1+dp[j]);
                    
        //         }

        //     }
        //     mx=max(dp[i],mx);
        // }
        // return mx;
    }
};