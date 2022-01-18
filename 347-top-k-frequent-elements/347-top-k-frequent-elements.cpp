typedef pair<int,int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> min_heap;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            min_heap.push({i->second,i->first});
            if(min_heap.size()>k) min_heap.pop();
        }
        vector<int> res;
        while(!min_heap.empty()){
           
                res.push_back(min_heap.top().second);
            min_heap.pop();
            }
        
        return res;
    }
};