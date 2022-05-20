class Solution {
public:
    int solve(vector<int> v,int k,int idx,int ans){
        if(v.size()==1) {
            return ans= v[0];
            //return ans;
        }
        idx=(idx+k)%v.size();
        v.erase(v.begin()+idx);
        ans= solve(v,k,idx,ans);
        return ans;
    }
    int findTheWinner(int n, int k) {
        if(n==1 or k==1)return n;
        int ans=-1;
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k=k-1;
        ans=solve(v,k,0,ans);
        return ans;
    }
};