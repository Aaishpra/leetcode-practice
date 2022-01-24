class Solution {
public:
    int longestSubstring(string s, int k) {
     unordered_map<char,int> mp;
     //int i=0,j=0;
        int maxlen=0;
        for(auto c:s){
            mp[c]++;
        }
        int maxUnique=mp.size();
        
          int countMap[26];
        //int maxUnique = getMaxUniqueLetters(s);
        int result = 0;
        for (int currUnique = 1; currUnique <= maxUnique; currUnique++) {
            // reset countMap
            memset(countMap, 0, sizeof(countMap));
            int windowStart = 0, windowEnd = 0, idx = 0, unique = 0, countAtLeastK = 0;
            while (windowEnd < s.size()) {
                // expand the sliding window
                if (unique <= currUnique) {
                    idx = s[windowEnd] - 'a';
                    if (countMap[idx] == 0) unique++;
                    countMap[idx]++;
                    if (countMap[idx] == k) countAtLeastK++;
                    windowEnd++;
                }
                // shrink the sliding window
                else {
                    idx = s[windowStart] - 'a';
                    if (countMap[idx] == k) countAtLeastK--;
                    countMap[idx]--;
                    if (countMap[idx] == 0) unique--;
                    windowStart++;
                }
                if (unique == currUnique && unique == countAtLeastK)
                    result = max(windowEnd - windowStart, result);
            }
        }

        return result;
    }
};