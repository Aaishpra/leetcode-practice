class Solution {
public:
    int solve(vector<int> v,int k,int idx){
        if(v.size()==1) {
            return v[0];
            //return ans;
        }
        idx=(idx+k)%v.size();
        v.erase(v.begin()+idx);
        return solve(v,k,idx);
        
    }
    int findTheWinner(int n, int k) {
        if(n==1 or k==1)return n;
        
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k=k-1;
        return solve(v,k,0);
    }
};