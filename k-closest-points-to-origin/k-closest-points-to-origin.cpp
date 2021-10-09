class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,pair<int,int>>> maxh;
        for(int i=0;i<points.size();i++){
            maxh.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]} });
            if(maxh.size()>k) maxh.pop();
        }
        vector<vector<int> > ans;
        while(!maxh.empty()){
            int x = maxh.top().second.first;
            int y = maxh.top().second.second;
            ans.push_back({x, y});
            maxh.pop();
        }
        return ans;
    }
};

        // int n = points.size();
        // priority_queue<pair<int, pair<int, int>>> pq;
        // for (int i = 0; i < n; i++)
        // {
        //     int x = points[i][0], y = points[i][1];
        //     int dist = x * x + y * y;
        //     pq.push({-dist, {x, y}});
        // }
        // vector<vector<int>> ans;
        // for (int i = 0; i < k; i++)
        // {
        //     int x = pq.top().second.first;
        //     int y = pq.top().second.second;
        //     ans.push_back({x, y});
        //     pq.pop();
        // }
        // return ans;