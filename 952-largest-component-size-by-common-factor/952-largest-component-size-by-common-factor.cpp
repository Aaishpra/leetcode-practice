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
    int largestComponentSize(vector<int>& nums) {
     int n=*max_element(nums.begin(),nums.end());
        UnionFind uf(n+1);
        
        for(auto a:nums){
            for(int k=2;k<=sqrt(a);k++){
                if(a%k==0){
                uf.unionSet(a,k);
                uf.unionSet(a,a/k);
                }
            }
        }
        
        unordered_map<int, int> mp;
       
        int ans = 1;
        
        for (int a : nums) {
            ans = max(ans, ++mp[uf.find1(a)]);
        }
        return ans;
    }
};