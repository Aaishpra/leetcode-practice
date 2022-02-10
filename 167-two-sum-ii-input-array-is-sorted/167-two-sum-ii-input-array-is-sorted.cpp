class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
        vector<int> res;
        int lo=0, hi=n-1;
        while(lo<hi){
            if(nums[lo]+nums[hi]==target) {
                res.push_back(lo+1);
                res.push_back(hi+1);
                while(lo+1<hi and nums[lo]==nums[lo+1])lo++;
                while(lo<hi-1 and nums[hi]==nums[hi-1])hi--;
                lo++,hi--;
            }
            else if(nums[lo]+nums[hi]<target) lo++;
            else hi--;
        }
        return res;
    }
};