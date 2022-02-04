class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int>mp;
    int ans = INT_MIN;
    int one = 0;
    for(int i = 0 ; i<nums.size() ; i++){
        one += (nums[i] == 1) ? 1 : -1;
        if(one == 0)ans =  i + 1;
        else if(mp.find(one) != mp.end()){
            ans = max(ans , i - mp[one]);
        }else{
            mp[one] = i;
        }
    }
    return ans == INT_MIN ? 0 : ans;
    }
};