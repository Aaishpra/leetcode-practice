class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        
        while(k>0){
            int tp=pq.top();
            pq.pop();
            tp-=floor(tp/2);
            pq.push(tp);
            k--;
        }
        
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};