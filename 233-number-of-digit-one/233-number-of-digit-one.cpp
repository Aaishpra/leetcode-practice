class Solution {
public:
    vector<int> nums;
    int dp[10][10][2];
    void binary(int n){
        while(n>0){
            nums.push_back(n%10);
            n=n/10;        
        }
        reverse(nums.begin(),nums.end());
    }
    
    long long solve(int R,int idx,int cnt,bool tight){
        if(idx==nums.size()){
            return cnt;
        }
        if(dp[idx][cnt][tight]!=-1)return dp[idx][cnt][tight];
        long long ans=0;
        int ub=tight?nums[idx]:9;
        for(int i=0;i<=ub;i++){
            int newcnt=(i==1)?cnt+1:cnt;
           //  int nflag=tight || i!=tight;
            ans+=solve(R,idx+1,newcnt,(tight and (i==ub)));
        }
        return dp[idx][cnt][tight]=ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof dp);
        binary(n);
        return solve(n,0,0,1);
    }
};