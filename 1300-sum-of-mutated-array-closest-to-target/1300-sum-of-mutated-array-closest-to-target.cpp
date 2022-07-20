class Solution {
public:
    int isValid(vector<int>& arr, int target,int mid,int n){
        std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=min(arr[i],mid);
        }
        return abs(target-sum);
    }
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        int lo=0;
        int hi=target;
        
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(arr,target,mid,n)<=isValid(arr,target,mid+1,n)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};