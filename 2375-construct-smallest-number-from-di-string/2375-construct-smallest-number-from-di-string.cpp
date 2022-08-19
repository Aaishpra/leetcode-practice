class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
	vector<int> v;
	for(int i = 1 ; i <= n + 1 ; i++) v.push_back(i);
	do{
		string cur;
		for(int i = 1 ; i <= n ; i++){
			if(v[i] > v[i - 1]) cur += 'I';
			else cur += 'D';
		}
		if(cur == pattern){
			string ans;
            for(int i:v){
                ans.push_back(i+'0');
            }
			return ans;
		}
	}while(next_permutation(v.begin(), v.end()));
	return "";
    }
};