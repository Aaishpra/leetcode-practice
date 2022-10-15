class Solution {
public:
    int halveArray(vector<int>& nums) {
    priority_queue<double> pq(nums.begin(),nums.end());
    double sum=accumulate(nums.begin(),nums.end(),0.0);
    double som=0.0;
        int cnt=0;
        while(som<sum/2){
            double x=pq.top();pq.pop();
            som+=x/2;
            pq.push(x/2);
            cnt++;
        }
        return cnt;
    }
};