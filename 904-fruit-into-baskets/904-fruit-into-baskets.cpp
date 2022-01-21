class Solution {
public:
    int totalFruit(vector<int>& s) {
      unordered_map<int, int> mp;
        int i=0;
        int j=0;
        int mx=0;
        if (s.size()==0 or s.size()==1 or s.size()==2) return s.size();
        while(j<s.size())
        {
            mp[s[j]]++;
            if (mp.size()<=2)
            {
                mx=max(mx,j-i+1);
            }
            else if (mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[s[i]]--;
                    if (mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
              
                }
              
            }
            j++;
        }
        return mx;
    }
};