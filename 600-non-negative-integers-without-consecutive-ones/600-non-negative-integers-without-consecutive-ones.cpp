class Solution {
public:
    int dp[33][2][2];
    vector<int> nums;
    
    void binary(int n){
        while(n>0){
            nums.push_back(n%2);
            n=n/2;
        }
        reverse(nums.begin(),nums.end());
    }
    long long solve(int R,int idx,int prev, bool tight){
        if(idx==nums.size()){
            return 1;
        }
        int ub=tight?nums[idx]:1;
        long long ans=0;
        if(dp[idx][prev][tight]!=-1)return dp[idx][prev][tight];
        
        for(int i=0;i<=ub;i++){
            if(i==1 and prev==1) continue;
           // new_tight=(i<ub)?
            ans+=solve(R,idx+1,i,(tight and(i==ub)));
        }
        return dp[idx][prev][tight]=ans;
    }
    int findIntegers(int n) {
        memset(dp,-1,sizeof dp);
        binary(n);
        return solve(n,0,0,1);
    }
};