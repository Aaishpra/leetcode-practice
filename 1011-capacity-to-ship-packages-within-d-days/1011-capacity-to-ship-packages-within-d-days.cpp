class Solution {
public:
    bool isValid(vector<int> &weights,int days,int curr_ans){
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
    int start=0;
    int end=0;
    int res=0;
    for(int i=0;i<weights.size();i++)end+=weights[i];

    while(start<=end){
        int mid=(start)+(end-start)/2;
        if(isValid(weights,days,mid)){
            res=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}
};