class Solution {
bool canHarvest(vector<int>& bDay, int harvestDay, int m, int k) {
    int adjacent = 0;
    for (auto bloomDay : bDay) {
        adjacent = bloomDay <= harvestDay ? adjacent + 1 : 0;
        if (adjacent == k) {
            adjacent = 0;
            --m;
        }
    }
    return m <= 0;
}
public:
int minDays(vector<int>& bDay, int m, int k) {
    int mx=INT_MIN;
    for(int i:bDay){
        mx=max(i,mx);
    }
    if (m * k > bDay.size())
        return -1;
    auto lo = 1, hi = mx;
    while (lo < hi) {
        auto mid = (hi + lo) / 2;
        if (canHarvest(bDay, mid, m, k))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
};