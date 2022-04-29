class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int k=coins;
        int cnt=0;
        int i=0;
        while(k>0 and i<costs.size() and k>=costs[i]){
           k=k-costs[i];
            i++;
            cnt++;
        }
        return cnt;
    }
};