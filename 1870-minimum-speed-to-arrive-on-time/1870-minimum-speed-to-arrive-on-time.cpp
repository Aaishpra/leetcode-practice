class Solution {
public:
    bool isValid(vector<int>& a,int mid,double hour){
        double time = 0;
    for (int i = 0; i < a.size(); i++) {
        time = ceil(time);
        time +=  (double)a[i] / mid;
        if (time > hour) return false;
    }
    return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo=1;
        int hi=1e9;
        int res=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(dist,mid,hour)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};