class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
     unordered_map<int,int> mp;
        
        for(int n:nums) mp[n]++;
        priority_queue<pair<int,int>> pq;
        for(auto m:mp){
            pq.push({-m.second,m.first});
        }
        vector<int> res;
        
        while(!pq.empty()){
            int rs=abs(pq.top().first);
            while(rs>0){
            res.push_back(pq.top().second);
            rs--;
            }
            pq.pop();
        }
        return res;
    }
};