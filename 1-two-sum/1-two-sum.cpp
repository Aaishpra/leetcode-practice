class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int number=target-nums[i];
            if(mp.find(number)!=mp.end()){
                result.push_back(mp[number]);
                result.push_back(i);
            }
            mp[nums[i]]=i;
        }
        return result;
    }
};