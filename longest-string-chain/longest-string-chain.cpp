class Solution {
public:
    bool isOk(const string& w1, const string& w2) {
        if (w1.size() - w2.size() != 1) return false;
        int i = 0, j = 0;
        while (i < w1.size() && j < w2.size()) {
            w1[i] == w2[j] ? i++, j++ : i++; 
        }
        return j == w2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto& lhs, auto& rhs){
            return lhs.size() < rhs.size();
        });
        vector<int> dp(words.size(), 1);
        int res = 1;
        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (isOk(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};