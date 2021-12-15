class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
     int res = -1;
        
        if (grid.empty() || grid[0].empty())
        {
            return res;
        }
        
        vector<vector<int>> gridValues(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        
        queue<pair<int, int>> q;
        
		// Step 1: find all lands and push them to a queue. Mark the distance to themselves as 0.
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    gridValues[i][j] = 0;
                }
            }
        }
        
        if (q.empty())
        {
            return -1;
        }
        
        vector<int> dx({0, 1, 0, -1});
        vector<int> dy({1, 0, -1, 0});
        
        while (!q.empty())
        {
            auto pos = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i)
            {
                int x = pos.first + dx[i];
                int y = pos.second + dy[i];
                
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
                {
                    if (gridValues[x][y] == INT_MAX)
                    {
                        q.push(make_pair(x, y));
                    }
                    
					// Step 2: The current cell should be updated to the distance to nearest land cell. 
                    gridValues[x][y] = min(gridValues[x][y], gridValues[pos.first][pos.second] + 1);
                }
            }
        }
        
		// Step 3: find the maximum values in gridValues.
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    res = max(res, gridValues[i][j]);
                }
            }
        }
        
        return res;
    }
};