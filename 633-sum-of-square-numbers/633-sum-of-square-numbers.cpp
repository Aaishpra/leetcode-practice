class Solution {
public:
    bool judgeSquareSum(int c) {
    set<int> s;
        int sqc = sqrt(c);
        for (int i = 0; i <= sqc; ++i) {
            s.insert(c - i*i);
            if (s.count(i*i)) return true;
        }
        return false;
    }
};