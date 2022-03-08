class Solution {
public:
    bool isValid(vector<int>& arr,int curr_ans, int days){
     int d=1;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>curr_ans){
                sum=arr[i];
                d++;
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int mx=INT_MIN;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            mx=max(mx,weights[i]);
        }
        int res=0;
        int lo=mx,hi=sum;
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