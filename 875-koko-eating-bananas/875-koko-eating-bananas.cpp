class Solution {
    int isValid(vector<int>& arr,int h,int mid){
        int curh=0;
        for(int i=0;i<arr.size();i++){
            curh+=arr[i]/mid;
            if(arr[i]%mid!=0) curh++;
        }
        return curh<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=INT_MIN;
        for(int i=0;i<piles.size();i++){
            mx=max(mx,piles[i]);
        }
        
        int lo=1,hi=mx;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(piles,h,mid)==true) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};