class Solution {
public:
    vector<int> ans;
     void backtrack(long long num,int n,int k){
        if(n==0){ 
            ans.push_back(num);
            return;}
         
        int lower=((num==0)?1:0);
        for(int i=lower;i<10;i++){
            if(num and abs(i-num%10)!=k) continue;
            num*=10;
            num+=i;
            backtrack(num,n-1,k);
            num/=10;
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        long long num=0;
        backtrack(num,n,k);
        return ans;
    }
};