class Solution {
public:
    int minimumSum(int n) {
        vector<int> d(4);
        for(int i=0;i<4;i++){
            d[i]=n%10;
            n=n/10;
        }
        sort(d.begin(),d.end());
        int ans =10*(d[0]+d[1])+d[2]+d[3];
        return ans;
    }
};