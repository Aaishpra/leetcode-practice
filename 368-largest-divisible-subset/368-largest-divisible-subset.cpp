class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
       sort(nums.begin(),nums.end());
        int mx_idx=0;
        vector<int> prev(n,-1);
     for(int i=1; i<n; i++) {
           for(int j=0; j<i; j++) {
               if(nums[i]%nums[j]==0 and dp[i] < dp[j] + 1) {
                   dp[i] = dp[j]+1;
                   prev[i] = j;
               }
           }
           if(dp[i] > dp[mx_idx]) {
               mx_idx = i;
           }
       }
       vector<int> answer;
      int t = mx_idx;  
      while(t >= 0) {
          answer.push_back(nums[t]);
          t = prev[t];
      }
       
      return answer;  
    }
};