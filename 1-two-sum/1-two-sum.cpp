class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int number=target-nums[i];
            if(mp.count(number)>0)
                return {mp[number],i};
            
            mp[nums[i]]=i;
        }
        return {};
    }
};