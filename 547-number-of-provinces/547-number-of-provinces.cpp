class UnionFind {
  public:
    vector < int > root;
    vector < int > rank;
  public:
    UnionFind(int sz): rank(sz), root(sz) {
      for (int i = 0; i < sz; i++) {
        root[i] = i;
        rank[i] = 1;
      }
    }
  int find1(int x) {
    if (x == root[x])
      return x;
    return root[x] = find1(root[x]);
  }

  void unionSet(int x, int y) {
    int root_x = find1(x);
    int root_y = find1(y);
    if (root_x != root_y) {
      if (rank[root_x] > rank[root_y]) {
        root[root_y] = root_x;
      } else if (rank[root_x] < rank[root_y]) {
        root[root_x] = root_y;
      } else {
        root[root_y] = root_x;
        rank[root_x] += 1;
      }
      // return true;
    }
    //return false;
  }
  bool isConnected(int x, int y) {
    return find1(x) == find1(y);
  }

};
class Solution {
  public:

    int findCircleNum(vector < vector < int >> & grid) {
      if (grid.empty()) return 0;

      int m = grid.size();
      int n = grid[0].size();
      UnionFind uf(n + 1);
      //int n=M.size();
      vector < int > v(n, -1); //there will be maximum n group, mark all as a leader

      //making group
      for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          if (grid[i][j] == 1)
          {
            uf.unionSet(i, j);
          }
        }
      }
        
      unordered_map < int, int > mp;
      
      int groups = 0;
      
    for(int i=0;i<n;i++) {
            if(uf.root[i] == i)
                groups++;
        }
        
        return groups;
    }

};