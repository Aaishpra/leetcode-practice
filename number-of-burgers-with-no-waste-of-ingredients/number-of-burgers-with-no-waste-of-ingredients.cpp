class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
         if (t % 2 == 0 && c * 2 <= t && t <= c * 4)
            return {t / 2 - c, c * 2 - t / 2};
        return {};
    }
};