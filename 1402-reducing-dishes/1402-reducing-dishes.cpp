class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int n=sat.size();
        int ans=0;
        int score=0,sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=sat[i];
            score+=sum;
             
            ans = max(ans,score);
        }
        return ans;
    }
};