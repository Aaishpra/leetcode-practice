class Solution {
public:
    bool isValid(vector<int>& piles,int h, int mid){
        int curh=0;
        for(int p:piles){
            curh+=p/mid;
            if(p%mid!=0)curh++;
        }
        return curh<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int res=0;
        int lo=1,hi=*max_element(piles.begin(),piles.end());
        while(lo<=hi){
         int mid=lo+(hi-lo)/2;
            if(isValid(piles,h,mid)==true){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};