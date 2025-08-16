class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {}

    int next(int price) {
        if (st.empty()) {
            st.push({price, 1});
            return 1;
        }

        if (price < st.top().first) {
            st.push({price, 1});
            return 1;
        }

        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */