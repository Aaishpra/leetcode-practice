class Solution {
public:
     int dp[1001][1001];
    //Top-down memoization
    int help(int i,vector<int> &mul,vector<int>& nums, int s){
        if(mul.size()==i)return 0;
        
        if(dp[i][s]!=-1)return dp[i][s];
        int e=nums.size()-(i-s)-1;
        int op1=mul[i]*nums[s]+help(i+1,mul,nums,s+1);
        int op2=mul[i]*nums[e]+help(i+1,mul,nums,s);
        
        return dp[i][s]=max(op1,op2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
       
        memset(dp,-1,sizeof(dp));
        return help(0,multipliers,nums,0);
    }
};