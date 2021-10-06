class Solution {
public:
    int minimumMoves(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'O') count++, i += 2;
        }
    return count;}
};