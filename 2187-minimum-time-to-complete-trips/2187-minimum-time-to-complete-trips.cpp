class Solution {
public:
    long long int function(vector<int> &time, long long giventime){
        long long int totaltime=0;
        for(auto t: time){
            long long val=t;
            totaltime+=giventime/val;
        }
        return totaltime;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int lo=1, hi=1e14;
        
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            if(function(time,mid)>=totalTrips){
                hi=mid;
            }
            else {lo=mid+1;}
        }
        return lo;
    }
};