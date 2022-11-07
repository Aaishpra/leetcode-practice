class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res=0;
        int lo=0,hi=costs.size()-1;
        priority_queue<int,vector<int>,greater<int>> pq,pq1;
        int cnt=0;
        while(cnt<k){
            while(pq.size() < candidates and lo <= hi) pq.push(costs[lo++]);
            while(pq1.size() < candidates and hi >= lo) pq1.push(costs[hi--]);
            if(pq1.size() == 0 or (pq.size() > 0 and pq.top() <= pq1.top())){
                res+=pq.top();
                pq.pop();
            }
            else if(pq.size() == 0 or (pq1.size() > 0 and pq1.top() < pq.top()))
            {
                res+=pq1.top();
                pq1.pop();
            }
            cnt++;
        }
        return res;
    }
};