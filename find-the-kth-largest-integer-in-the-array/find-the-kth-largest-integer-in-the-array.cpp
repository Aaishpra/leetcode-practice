class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        multimap<string, int> mp;
        for(int i=0;i<n;i++){
            int x = nums[i].size();
            mp.insert(make_pair(nums[i],x));
        }
        priority_queue<pair<int,string>>p;
        for(auto it : mp){
            p.push({it.second,it.first});
        }
        while(!p.empty() && k!=1){
            p.pop(); k--;
        }
        return p.top().second;
    }
};