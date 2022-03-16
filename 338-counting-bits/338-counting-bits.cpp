class Solution {
public:
    vector<int> countBits(int n) {
     
        vector<int> res;
        int count;
        for(int i=0;i<=n;i++){
             count=0;
            int n=i;
            while(n){
                count++;
                n=n&n-1;
            }
            res.push_back(count);
        }
        return res;
    }
};