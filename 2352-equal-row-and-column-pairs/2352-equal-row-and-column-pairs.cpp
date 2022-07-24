class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
     vector<vector<int>> tr(grid.size(), vector<int>(grid[0].size()));;
     
      for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            tr[i][j] = grid[j][i];
        }
      }
      
      int count = 0;
      
      for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < tr.size(); j++){
          if(grid[i] == tr[j]){
            count++;
          }
        }
      }
      
      return count;   
    }
};