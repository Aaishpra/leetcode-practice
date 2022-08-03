class MyCalendar {
public:
    vector<vector<int>> ar;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<ar.size();i++){
            if(!(ar[i][0]>=end or start>=ar[i][1])){
                return false;
            }
        }
               ar.push_back({start,end});
               return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */