class Solution {
public:
    bool isValid(vector<int>&weights,int mid,int days){
        int d=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid)
            {sum=weights[i];
                d++;
        }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);
        int res=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(weights,mid,days)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};