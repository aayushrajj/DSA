class MyCalendarTwo {
public:
    set<pair<int,int>> books;
    set<pair<int,int>> doubleBooks;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto v : doubleBooks)
            if(v.first < end && start < v.second)
                return false;
        
        for(auto v : books)
            if(v.first < end && start < v.second)
                doubleBooks.insert( {max(start,v.first) , min(end,v.second) });
        
        books.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */