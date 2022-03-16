class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        for(int i=0;i<k;i++){
            int tp=pq.top();
            pq.pop();
            tp-=tp/2;
            pq.push(tp);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};