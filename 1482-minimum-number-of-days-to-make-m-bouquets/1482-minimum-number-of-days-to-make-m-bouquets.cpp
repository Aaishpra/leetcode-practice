class Solution {

    bool isValid(vector<int>& bloomDay, int m, int k, int mid) {

		int count = 0, size = 0;
		for (int i = 0; i < bloomDay.size(); i++) {
			size = (bloomDay[i] <= mid) ? size+1 : 0;
			if (size == k) size = 0, count++;
			if (count == m)
				return true;
		}

		return false;
	}
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		if(bloomDay.size() == 0 || m == 0 || k == 0) return 0;
		if (m * k > bloomDay.size()) return -1;

		int l = INT_MAX, r = INT_MIN;
		for (int i = 0; i < bloomDay.size(); i++) {
			l = min(l, bloomDay[i]);
			r = max(r, bloomDay[i]);
		}

		while (l <= r) {
			int mid = l + (r-l)/2;

			if (isValid(bloomDay, m, k, mid))
				r = mid-1;
			else
				l = mid+1;
		}

		return l;
	}
};