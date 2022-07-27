class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n= cardPoints.size();
        
        vector<int> sumfront(n+1,0);
        vector<int> sumbehind(n+1,0);
        sum=0;
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
            sumfront[i+1]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=cardPoints[i];
            sumbehind[i]=sum;
        }
        
        int answer=0;
        for(int i=0;i<=k;i++){
            answer=max(answer,sumfront[i]+sumbehind[n-k+i]);
        }
        return answer;
    }
};