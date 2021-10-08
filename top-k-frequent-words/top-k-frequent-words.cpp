class Solution {
public:
     struct compare{
        bool operator()(pair<string,int> a,pair<string,int> b){
            string str1 = a.first;
            string str2 = b.first;
            if(a.second == b.second)
                return str1.compare(str2) > 0 ? true : false;
            return a.second < b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto word:words){
            mp[word]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> pq;
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        vector<string> ans;
        while(k--){
            pair<string,int> p = pq.top();
            ans.push_back(p.first);
            pq.pop();
        }
        return ans;
    }
};