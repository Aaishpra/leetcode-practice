class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // State machine
        if(prices.size() < 2 || k == 0) return 0;
		vector<int> state(2 * k, INT_MIN);
		state[0] = -prices[0];

		for(auto& it:prices){
			state[0] = max(state[0], -it);
			state[1] = max(state[1], state[0] + it);
			for(int i = 1 ; i < k; ++i){
				state[2 * i] = max(state[2 * i], state[2 * i - 1] - it);
				state[2 * i + 1] = max(state[2 * i + 1], state[2 * i] + it);
			}
		}

		return state.back();
    }
};