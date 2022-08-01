class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int target=-nums[i];
            int lo=i+1,hi=n-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]<target) lo++;
                else if(nums[lo]+nums[hi]>target)hi--;
                else {
                    res.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo+1<hi and nums[lo]==nums[lo+1]) lo++;
                    while(lo<hi-1 and nums[hi]==nums[hi-1]) hi--;
                    lo++;
                    hi--;
                }
            }
        }
        return res;
    }
};