class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int len=num.size()-1;
        while(len >= 0 || k != 0){
            
            if(len >= 0){
                k += num[len--];
            }
            
            result.push_back(k % 10);
            k /= 10;
        }
            reverse(result.begin(),result.end());
        return result;
    }
};