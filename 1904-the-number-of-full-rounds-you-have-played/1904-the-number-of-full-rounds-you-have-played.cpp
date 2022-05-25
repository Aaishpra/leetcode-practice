class Solution {
public:
    int numberOfRounds(string s, string f) {
        int start=stoi(s.substr(0,2))*60+stoi(s.substr(3));
        int finish=stoi(f.substr(0,2))*60+stoi(f.substr(3));
        if(start>=finish) finish+=24*60;
        return max(0,(finish/15)-(start+14)/15);
    }
};