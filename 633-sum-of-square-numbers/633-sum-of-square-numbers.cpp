class Solution {
public:
    bool judgeSquareSum(int c) {
     if(c<0)return false;
        long long int lo=0,hi=sqrt(c);
        while(lo<=hi){
            long long int cur=lo*lo+hi*hi;
            if(cur<c){
                lo++;
            }
            else if(cur>c){
                hi--;
            }
            else return true;
        }
        return false;    
    }
};