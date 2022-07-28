class Solution {
public:
    int countTriplets(vector<int>& arr) {
     int cnt=0;
        for(int i=0;i<arr.size();i++){
            int x=arr[i];
            for(int j=i+1;j<arr.size();j++){
               x=x xor arr[j];
                if(x==0){
                    cnt+=j-i;
                }
            }
        }
        return cnt;
    }
};