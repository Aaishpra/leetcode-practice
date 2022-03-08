class Solution {
    int bs(vector<pair<pair<int,int>,int>> &sorted,int x){
        int n=sorted.size();
        if(sorted[n-1].first.first<x){
            return -1;
        }
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(sorted[mid].first.first>=x){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return sorted[lo].second;
    }
public:
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<pair<int,int>,int>> sorted;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            sorted.push_back({{intervals[i][0],intervals[i][1]},i});
        }
        sort(sorted.begin(),sorted.end());
        vector<int> res(n,-1);
        
        for(int i=0;i<n;i++){
            res[i]=bs(sorted,intervals[i][1]);
        }
        return res;
    }
};