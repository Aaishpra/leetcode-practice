class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size();
        int mx=0;
        sort(points.begin(),points.end());
        for(int i=1;i<points.size();i++){
            mx=max(points[i][0]-points[i-1][0],mx);
        }
        return mx;
    }
};