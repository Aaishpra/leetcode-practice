class Solution {
public:
    bool isValid(vector<int>& weights,int curr_ans, int days){
       int days_now=1;
int curr_wt=0;
for(int i=0;i<weights.size();i++){
if(weights[i]>curr_ans)return false;

        if(curr_wt+weights[i]>curr_ans){
            curr_wt=weights[i];
            days_now++;
            if(days_now>days)return false;
        }
        else{
            curr_wt+=weights[i];
        }
    }
    return true;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int res=-1;
        int lo=0,hi=sum;
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