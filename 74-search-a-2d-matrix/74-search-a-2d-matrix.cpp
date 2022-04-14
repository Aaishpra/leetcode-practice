class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Binary search with tweak
        int n=matrix.size(), m=matrix[0].size();
        int lo=0, hi=m*n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(matrix[mid/m][mid%m]==target) return true;
            else if(matrix[mid/m][mid%m]>target) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};