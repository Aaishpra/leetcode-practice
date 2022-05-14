class Solution {
public:
    string largestGoodInteger(string nums) {
     string ans="";
        for(int i=2;i<nums.size();i++){
            if(nums[i]==nums[i-1] and nums[i-1]==nums[i-2] and nums[i]==nums[i-2])
                ans=max(ans,{nums[i-2],nums[i-1],nums[i]});
        }
        return ans;
    }
};