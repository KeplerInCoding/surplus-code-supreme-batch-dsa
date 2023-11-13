//medium



class StockSpanner {
public:
    stack <pair<int,int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        int count = 1;
        pair <int, int> p;
        p.first = price;
        while(!s.empty() && s.top().first<=price){
            count+=s.top().second;
            s.pop();
            p.second = count;
        }
        p.second=count;
        s.push(p);
        return count;
    }
};



/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */