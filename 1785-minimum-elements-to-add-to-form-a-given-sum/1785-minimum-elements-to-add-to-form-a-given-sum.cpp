class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=accumulate(nums.begin(),nums.end(),0l);
        long long remain=abs(goal-sum);
        long long ans=remain/limit;
        if(remain%limit==0) return ans;
        return ans+1;
    }
};