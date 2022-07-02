return true;
}
return false;
}
​
bool connected(int x, int y) {
return find(x) == find(y);
}
​
private:
vector<int> root;
vector<int> rank;
};
​
​
​
​
class Solution {
public:
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
int n=edges.size();
UnionFind uf(n+1);
for(auto e:edges){
if(!uf.unionSet(e[0],e[1]))return e;
}
return {};
}
};
```