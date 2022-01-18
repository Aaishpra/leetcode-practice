typedef pair<int,char> pi;
class Solution {
public:
    string frequencySort(string s) {
     priority_queue<pi> max_heap;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }    
        
        for(auto i=mp.begin();i!=mp.end();i++){
            max_heap.push({i->second,i->first});
        }   
        string ans="";
        while(!max_heap.empty()){
            for(int i=0;i<max_heap.top().first;i++){
                ans+=max_heap.top().second;
            }
            max_heap.pop();
        }
        return ans;
    }
};