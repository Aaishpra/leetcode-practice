class Solution {
public:
    int isValid(vector<int>& dist,int mid,double hour){
        int hr=0;
        int n=dist.size();
        double res=0;
        for(int i=0;i<dist.size()-1;i++){
            hr+=dist[i]/mid;
            if(dist[i]%mid!=0) hr++;
        }
        res=hr+(double)dist[n-1]/mid;
        return res<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo=1,hi=1e9;
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