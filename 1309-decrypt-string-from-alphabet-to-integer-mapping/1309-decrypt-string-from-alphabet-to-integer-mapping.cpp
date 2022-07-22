class Solution {
public:
    string freqAlphabets(string s) {
     string ans = "";
        
        for(int i = s.size() - 1; i >= 0;)
        {
            if(s[i] == '#')
            {
                int n = stoi(s.substr(i-2, 2));
                ans += char(n + 96);
                i -= 3;
            }
            else
            {
                ans += char(s[i] - '0' + 96);
                i--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
       
    }
};