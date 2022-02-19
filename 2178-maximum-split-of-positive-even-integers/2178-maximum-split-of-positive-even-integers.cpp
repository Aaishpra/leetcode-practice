class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        vector<long long> ans;
        if(n%2)return {};
        int i=2;
        long long cursum=0;
        while((cursum+i)<=n){
             ans.push_back(i);
            cursum+=i;
            i=i+2;
        }
        int sz = ans.size();
        ans[sz-1] += (n-cursum);
        return ans;
    }
};