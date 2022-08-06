class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        int i=0;
      while(i<l.size()) {
      vector<int> ans;
          for(int j=l[i];j<=r[i];j++){
              ans.push_back(nums[j]);
          }
      sort(ans.begin(), ans.end());
      
      if(ans.size() == 1) { // Size should be at least two 
        res.push_back(false);
        continue;
      }
           int diff=ans[1]-ans[0];
            bool valid=true;
            for(int k=2;k<ans.size();k++){
                if(diff!=ans[k]-ans[k-1]) {
                 valid=false;
                    break;
                }
            }
            res.push_back(valid);
          i++;
       }

    return res;
    }
};