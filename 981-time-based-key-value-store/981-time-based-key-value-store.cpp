class TimeMap {
    unordered_map<string, map<int, string>>hm;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hm[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = hm[key].upper_bound(timestamp);
		return (it == hm[key].begin()) ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */