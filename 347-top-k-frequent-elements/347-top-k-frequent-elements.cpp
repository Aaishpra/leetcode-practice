
typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pi, vector<pi>, greater<pi> > pq;
  
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> res;
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
            if(pq.size()>k)pq.pop();}
            while(pq.size()>0){
                res.push_back(pq.top().second);
                pq.pop();
            }
        
        return res;
    }
};