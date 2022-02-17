class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
    int i=0,j=arr.size()-1;
        vector<int> ans;
        int mid=(arr.size()-1)/2;
        while(k-->0){
            if(abs(arr[j]-arr[mid])>=abs(arr[i]-arr[mid])){
                ans.push_back(arr[j]);
                j--;
            }
            else{
                ans.push_back(arr[i]);
                i++;
            }
        }
        return ans;
    }
};