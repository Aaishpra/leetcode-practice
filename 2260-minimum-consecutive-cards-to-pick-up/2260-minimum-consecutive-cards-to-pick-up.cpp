class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int left = 0, right = 0, res = INT_MAX;
	unordered_map<int, int> hmap;
	for (right = 0; right < cards.size(); right++) {
		if (++hmap[cards[right]] >= 2) {
			while (hmap[cards[right]] >= 2) {
				if ((cards[left] != cards[right]) 
					|| hmap[cards[left]] > 2) hmap[cards[left++]]--;
				else break;
			}
			res = min(res, right - left + 1);
		}
	}
	return res == INT_MAX ? -1 : res;
    }
};