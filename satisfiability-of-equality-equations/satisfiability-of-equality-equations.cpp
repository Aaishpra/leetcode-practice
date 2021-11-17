class Solution {
    public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<char>> graph(26, vector<char>());
        for (string equ : equations) {
            if (equ[1] == '=' && equ[0] != equ[3]) {
                graph[equ[0] - 'a'].push_back(equ[3]);
                graph[equ[3] - 'a'].push_back(equ[0]);
            }
        }
        vector<bool> isVisited(26, false);
        for (string equ : equations) {
            if ((equ[1] == '!' && hasPath(graph, isVisited, equ[0], equ[3])) || (equ[1] == '=' && !hasPath(graph, isVisited, equ[0], equ[3]))) {
                return false;
            }
        }
        return true;
    }
    
    bool hasPath(vector<vector<char>> &graph, vector<bool> isVisited, char cur, char &end) {
        isVisited[cur - 'a'] = true; // Mark as visited
        if (cur == end) { // Path Found
            return true;
        }
        bool res = false;
        for (char &child : graph[cur - 'a']) {
            if (isVisited[child - 'a'] == false) { // If not visited
                res |= hasPath(graph, isVisited, child, end);
            }
        }
        return res;
    }
};