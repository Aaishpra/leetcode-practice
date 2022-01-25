class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       int n=arr.size();
        
        if(n<3) return false;
        int pointer=1;
        
    while(pointer<n){
        if(arr[pointer-1]<arr[pointer])pointer++;
        else break;
    }
        if(pointer == n or pointer==1) return false;
        while(pointer<n){
            if(arr[pointer-1]>arr[pointer])pointer++;
            else break;
        }
        return pointer==n;
    }
};