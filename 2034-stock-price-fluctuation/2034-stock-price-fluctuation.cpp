class StockPrice {
public:
    unordered_map<int, int> map1; // <timestamp, price>
    map<int, int> map2;           // <price, appearance time>
    int minVal = INT32_MAX, maxVal = INT32_MIN;
    int currentTime = 0;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (map1.find(timestamp) != map1.end()) {
            int orig_price = map1[timestamp];
            map2[orig_price]--;
            if (map2[orig_price] == 0) {
                map2.erase(orig_price);
            }
        }
        
        map1[timestamp] = price;
        map2[price]++;
        currentTime = max(currentTime, timestamp);
    }
    
    int current() {
        return map1[currentTime];
    }
    
    int maximum() {
        auto item = map2.end();
        item--;
        return item->first;
    }
    
    int minimum() {        
        return map2.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */