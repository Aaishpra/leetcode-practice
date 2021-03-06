class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
    //int LIS[n+1];
        vector<int> LIS(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    LIS[i]=max(LIS[i],1+LIS[j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(LIS[i],ans);
        }
        return ans;
    }
};