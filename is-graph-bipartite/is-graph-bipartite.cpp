class Solution{
    
public:
bool isGraphBipartite(vector<vector<int>> &adjList, vector<int> &colors, int node, int color)
{
	colors[node] = color;

	for(auto &u : adjList[node])
	{
		if(colors[u] == color)
			return false;

		if(colors[u] == -1 and !isGraphBipartite(adjList, colors, u, !color))
			return false; //Ulta colour krkr false wali condition
	}

	return true;
}

// bool isGraphBipartiteBfs(vector<vector<int>> &adjList, vector<int> &colors, int node)
// {
// 	queue<pair<int, int>> mq;

// 	mq.push({ node, 0 });
// 	colors[node] = 0;

// 	while(!mq.empty())
// 	{
// 		auto p = mq.front();
// 		mq.pop();

// 		int u = p.first, color = p.second;

// 		for(auto &x : adjList[u])
// 		{
// 			if(colors[x] == color)
// 				return false;

// 			if(colors[x] == -1)
// 			{
// 				colors[x] = !color;
// 				mq.push({ x, !color });
// 			}
// 		}
// 	}

// 	return true;
// }

bool isBipartite(vector<vector<int>>& graph) {

	int n = graph.size();

	vector<int> colors(n, -1);

	for(int i = 0;i < n; i++)
	{
		if(colors[i] == -1 and !isGraphBipartite(graph, colors, i, 0))
			return false;
	}

	return true;}};