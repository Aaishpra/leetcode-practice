class Solution {
public:
      int binary_search(int key , vector<int>&nums){
        int low = 0 , high = nums.size()-1;
        int greater = nums.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>key){
                greater = mid;
                high = mid-1;
            }
            else 
                low = mid+1;
        }
        return nums.size()-greater;
    }
    // function to get the count of lexicographically smallest character
    int count( string s){
        sort(s.begin() , s.end());
        int cnt = 0;
        int i = 0;
        while(i < s.size()-1){
            if(s[i]!=s[i+1]) return cnt+1;
            cnt++;
            i++;
        }
        return cnt+1;
    }
    //  main function 
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> word , ans(queries.size());
        for(auto i :words){
            word.push_back(count(i));
        }
        // sorting the array of smaller frequency count to be use for binary search 
        sort(word.begin() , word.end());
        for(int i = 0 ; i < queries.size() ; i++){
            int cnt = count(queries[i]);
            ans[i] = binary_search(cnt , word);
        }
        return ans;
    }
};