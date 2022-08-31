class Solution {
public:
    static bool mysort(vector<int> &a,vector<int>& b){
        return a[0]+a[1]+a[2]< b[0]+b[1]+b[2];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        vector<int> sum;
        vector<int> dp(cuboids.size(),0);
        sort(cuboids.begin(),cuboids.end(),mysort);
        int i=0;
        //chosing highest dimension as height
        for(auto &c : cuboids) {
            sort(c.begin(), c.end());
            dp[i] = c.back();
            cout<<dp[i]<<" ";
            ++i;
        }
        //for(int n:dp) cout<<n<<" ";
        
        for(int i=0;i<cuboids.size();i++){
            dp[i]=cuboids[i][2];
            for(int j=0;j<i;j++){
                if(cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and cuboids[i][2]>=cuboids[j][2]){
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
        }
        
       // for(int n:dp) cout<<n<<" ";
        return *max_element(dp.begin(),dp.end());
    }
};