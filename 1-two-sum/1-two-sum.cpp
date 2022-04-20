class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int number=target-nums[i];
            if(mp.count(number)>0)
                return {mp[number],i};
            //Storing the element in key value pair of hashmap
            mp[nums[i]]=i;
        }
        return {};
    }
};