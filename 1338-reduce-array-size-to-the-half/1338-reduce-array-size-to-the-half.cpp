class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i:arr){
            mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        long long sum=0;
        int cnt=0;
        while(sum<n/2){
            sum+=pq.top().first;
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};