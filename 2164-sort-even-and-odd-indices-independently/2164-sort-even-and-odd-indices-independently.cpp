class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& arr) {
        int n=arr.size();
        vector<int> odd,even;
        for(int i=0;i<arr.size();i++){
            if(i%2)even.push_back(arr[i]);
            else odd.push_back(arr[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end(),greater<int>());
        int i=0,j=0;
        vector<int> ans;
        while(i<odd.size() or j<even.size()){
            if(i<odd.size()) ans.push_back(odd[i++]);
            if(j<even.size()) ans.push_back(even[j++]);
        }
    
        return ans;
    }
};