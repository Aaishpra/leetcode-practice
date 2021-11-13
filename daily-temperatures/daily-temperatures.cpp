class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     int n = temperatures.size();
stack<int> s;
vector<int> res;
for(int i=n-1; i>=0; i--) {
while(!s.empty() && temperatures[s.top()] <= temperatures[i]) {
s.pop();
}
res.push_back((s.size() == 0) ? 0 : s.top()-i);
s.push(i);
}
reverse(res.begin(),res.end());
return res;
    }
};