class Solution {
public:
    int solve(vector<int> v,int idx,int k){
        int ans=-1;
        if(v.size()==1){
            return ans=v[0];
        }
        idx=(idx+k)%v.size();
        v.erase(v.begin()+idx);
        ans=solve(v,idx,k);
        return ans;
    }
    int findTheWinner(int n, int k) {
        vector<int> v;
        if(n==0 or k==0) return 0;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        return solve(v,0,k-1);
    }
};